#!/usr/bin/env python3
"""
run-tests.py - Robust test runner for godot-cpp test project (with temp portable Godot copy)
"""

import argparse
import builtins
import os
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import time
import urllib.request
import zipfile
from pathlib import Path
from typing import Any, Dict, List, Tuple

# ----------------------------------------------
# Configuration
# ----------------------------------------------

GODOT_EDITOR = os.environ.get("GODOT_EDITOR", "unspecified-editor-binary")
GODOT_RELEASE = os.environ.get("GODOT_RELEASE", "unspecified-release-binary")
GODOT_DEBUG = os.environ.get("GODOT_DEBUG", "unspecified-debug-binary")

SCRIPT_DIR = Path(__file__).parent.resolve()
PROJECT_DIR = (SCRIPT_DIR / "project").resolve()

END_MARKER = "==== TESTS FINISHED ===="
PASSED_MARKER = "******** PASSED ********"
FAILED_MARKER = "******** FAILED ********"

TIMEOUT_SEC = 180
IMPORT_TIMEOUT_SEC = 30

FILTER_INCLUDE_PATTERNS = [
    re.compile(r"^.*={4}\s*TESTS\s*FINISHED\s*={4}"),  # ==== ... ====
    re.compile(r"^.*PASSES:\s*\d+"),  # PASSES: <number>
    re.compile(r"^.*FAILURES:\s*\d+"),  # FAILURES: <number>
    re.compile(r"^.*\*+\s*PASSED\s*\*+"),  # any number of stars around PASSED
    re.compile(r"^.*\*+\s*FAILED\s*\*+"),  # same for FAILED (useful for future)
]
FILTER_DISCARD_PATTERNS = [
    re.compile(r".*"),  # Discard everything that hasn't already been included.
]

IS_WINDOWS = sys.platform.startswith("win")

PORTABLE_EDITOR = "godot-editor.exe" if IS_WINDOWS else "godot-editor"
PORTABLE_RELEASE = "godot-release.exe" if IS_WINDOWS else "godot-release"
PORTABLE_DEBUG = "godot-debug.exe" if IS_WINDOWS else "godot-debug"
PORTABLE_MARKER = "_sc_"

PHASE_CLEANUP = 10
PHASE_PRE_IMPORT = 20
PHASE_UNIT_TESTS = 30

verbose: bool = False

# ----------------------------------------------
# Downloader
# ----------------------------------------------


def download_godot(version: str, arch: str) -> Path:
    """Download and extract a specific Godot version and architecture."""
    # Official builds are usually at:
    # https://github.com/godotengine/godot-builds/releases/download/<version>/Godot_v<version>_<arch>.zip
    url = f"https://github.com/godotengine/godot-builds/releases/download/{version}/Godot_v{version}_{arch}.zip"

    download_dir = (SCRIPT_DIR / "godot-builds").resolve()
    download_dir.mkdir(exist_ok=True)

    zip_path = download_dir / f"Godot_v{version}_{arch}.zip"

    if not zip_path.exists():
        print(f"→ Downloading Godot {version} ({arch})...")
        try:
            urllib.request.urlretrieve(url, zip_path)
            print("  [ DONE ]")
        except Exception as e:
            print(f"  [ FAILED ] - {e}")
            return Path()

    # Unzip
    print(f"→ Extracting Godot {version}...")
    try:
        with zipfile.ZipFile(zip_path, "r") as zip_ref:
            zip_ref.extractall(download_dir)
        print("  [ DONE ]")
    except Exception as e:
        print(f"  [ FAILED ] - {e}")
        return Path()

    # Find the binary
    binary_path = find_godot_binary(download_dir, version, arch)

    if binary_path and binary_path.exists():
        if not IS_WINDOWS and not binary_path.is_dir():
            binary_path.chmod(binary_path.stat().st_mode | 0o111)
        return binary_path.resolve()

    print(f"  [ FAILED ] - Could not find binary for Godot {version} in {download_dir}")
    return Path()


def find_godot_binary(download_dir: Path, version: str, arch: str) -> Path:
    """Search for the Godot binary in the download directory based on common patterns."""
    binary_name = f"Godot_v{version}_{arch}"

    # 1. Direct match
    p = download_dir / binary_name
    if p.is_file():
        return p

    # 2. Windows executable
    p = download_dir / (binary_name + ".exe")
    if p.is_file():
        return p

    # 3. macOS App bundle
    p = download_dir / "Godot.app"
    if p.is_dir():
        binary_p = p / "Contents" / "MacOS" / "Godot"
        if binary_p.is_file():
            return binary_p

    # 4. Fallback: Search for anything starting with Godot_v{version}
    for f in download_dir.iterdir():
        if f.is_file() and f.name.startswith(f"Godot_v{version}"):
            return f

    return Path()


def discover_artifacts():
    global GODOT_EDITOR, GODOT_RELEASE, GODOT_DEBUG
    artifacts_dir = SCRIPT_DIR.parent / "godot-artifacts"
    if not artifacts_dir.exists():
        return

    # Helper to find the best match for a pattern
    def find_binary(pattern_part):
        platform_part = "linux" if sys.platform.startswith("linux") else ("windows" if IS_WINDOWS else "macos")

        candidates = []
        for f in artifacts_dir.iterdir():
            if f.is_file() and platform_part in f.name and pattern_part in f.name:
                candidates.append(f)

        if not candidates:
            # Try without platform part as fallback
            for f in artifacts_dir.iterdir():
                if f.is_file() and pattern_part in f.name:
                    candidates.append(f)

        if candidates:
            # Prefer 'mono' if available, otherwise first one
            for c in candidates:
                if "mono" in c.name:
                    return str(c.resolve())
            return str(candidates[0].resolve())
        return None

    if GODOT_EDITOR == "unspecified-editor-binary":
        found = find_binary("editor")
        if found:
            GODOT_EDITOR = found

    if GODOT_RELEASE == "unspecified-release-binary":
        found = find_binary("template_release")
        if found:
            GODOT_RELEASE = found

    if GODOT_DEBUG == "unspecified-debug-binary":
        found = find_binary("template_debug")
        if found:
            GODOT_DEBUG = found


# ----------------------------------------------
# Helpers
# ----------------------------------------------
def record_test_result(results: List[Dict[str, Any]], version: str, success: bool, duration: int) -> None:
    status = "✅ PASSED" if success else "❌ FAILED"
    results.append({"godot_version": version or "master", "status": status, "duration_seconds": duration})


def vprint(*args, **kwargs):
    if verbose:
        print(*args, **kwargs)


def filter_output(lines: List[str]) -> List[str]:
    result = []
    for line in lines:
        cleaned = line.rstrip()
        if not cleaned:
            continue
        if any(pat.search(cleaned) for pat in FILTER_INCLUDE_PATTERNS):
            result.append(cleaned)
            continue
        if any(pat.search(cleaned) for pat in FILTER_DISCARD_PATTERNS):
            continue
        result.append(cleaned)
    return result


# ----------------------------------------------
# Portable Godot
# ----------------------------------------------


def setup_temp_portable_godot():
    vprint(f"\n{'-' * 10} Making Godot Portable {'-' * 10}") if verbose else print("→ Creating portable Godot", end=" ")

    vprint("→ Creating portable marker", end=" ")
    try:
        (Path.cwd() / PORTABLE_MARKER).touch(exist_ok=True)
        vprint("[ DONE ]")
    except OSError:
        print("[ FAILED ]" if verbose else "[ Failed to create portable marker ]")
        sys.exit(1)

    targets = [
        ("editor", GODOT_EDITOR, Path.cwd() / PORTABLE_EDITOR),
        ("template_release", GODOT_RELEASE, Path.cwd() / PORTABLE_RELEASE),
        ("template_debug", GODOT_DEBUG, Path.cwd() / PORTABLE_DEBUG),
    ]

    for name, src, dst in targets:
        vprint(f"→ Copying Godot {name}", end=" ")
        try:
            if (
                not src
                or src == "unspecified-editor-binary"
                or src == "unspecified-release-binary"
                or src == "unspecified-debug-binary"
            ):
                vprint("[ SKIPPED (not provided) ]")
                continue

            src_path = Path(src)
            if not src_path.exists():
                vprint(f"[ SKIPPED (not found: {src}) ]")
                continue

            src_fqp = src_path.resolve(True)
            if src_fqp == dst.resolve():
                vprint("[ SKIPPED (same path) ]")
                continue
            shutil.copy2(src_fqp, dst)

            # If it's a .NET/Mono build, copy the GodotSharp directory too
            src_godot_sharp = src_fqp.parent / "GodotSharp"
            if src_godot_sharp.exists() and src_godot_sharp.is_dir():
                dst_godot_sharp = Path.cwd() / "GodotSharp"
                if not dst_godot_sharp.exists():
                    vprint(" (with GodotSharp)", end="")
                    shutil.copytree(src_godot_sharp, dst_godot_sharp)

            # Ensure executable bit on non-Windows
            if not IS_WINDOWS:
                dst.chmod(dst.stat().st_mode | 0o111)
            vprint("[ DONE ]")
        except OSError as e:
            print(f"[ {e.strerror} ]")
            print(f"\t→ {e.filename}")
            sys.exit(1)

    print("") if verbose else print("[ DONE ]")


def cleanup_temp_portable():
    temp_editor = Path.cwd() / PORTABLE_EDITOR
    temp_release = Path.cwd() / PORTABLE_RELEASE
    temp_debug = Path.cwd() / PORTABLE_DEBUG
    temp_marker = Path.cwd() / PORTABLE_MARKER
    temp_godot_sharp = Path.cwd() / "GodotSharp"
    editor_data = Path.cwd() / "editor_data"

    cleaned = False
    for path in [temp_editor, temp_release, temp_debug, temp_marker]:
        if path.exists():
            try:
                path.unlink()
                cleaned = True
            except OSError:
                if verbose:
                    print(f"→ Failed to remove {path}")

    for path in [temp_godot_sharp, editor_data]:
        if path.exists():
            try:
                if path.is_file():
                    path.unlink()
                else:
                    shutil.rmtree(path)
                cleaned = True
            except OSError:
                if verbose:
                    print(f"→ Failed to clean {path}")

    if cleaned:
        print("→ Cleaned [ DONE ]")


# ----------------------------------------------
# Cache & Run
# ----------------------------------------------


def cleanup_godot_cache() -> bool:
    cache_dir = PROJECT_DIR / ".godot"
    if cache_dir.exists():
        if verbose:
            print("→ Cleaning project cache", end=" ")
        try:
            shutil.rmtree(cache_dir, ignore_errors=True)
            if verbose:
                print("[ DONE ]")
        except Exception as e:
            if verbose:
                print(f"[ FAILED ] {e}")
            return False
    return True


def run_godot(args: List[str], desc: str, godot_bin: str, timeout_sec: int = TIMEOUT_SEC) -> Tuple[int, str, str, str]:
    if verbose:
        print(f"\n{'-' * 10} {desc} {'-' * 10}")
        print(f"→ {godot_bin} {' '.join(args)}")

    with tempfile.TemporaryDirectory() as tmpdir:
        stdout_path = Path(tmpdir) / "stdout.txt"
        stderr_path = Path(tmpdir) / "stderr.txt"

        cmd = [godot_bin] + args

        try:
            start = time.time()
            proc = subprocess.Popen(
                cmd,
                stdout=stdout_path.open("wb"),
                stderr=stderr_path.open("wb"),
                cwd=os.getcwd(),
                start_new_session=True,
            )

            timeout = False
            while proc.poll() is None:
                if time.time() - start > timeout_sec:
                    proc.send_signal(signal.SIGTERM)
                    time.sleep(1)
                    if proc.poll() is None:
                        proc.kill()
                    proc.wait()
                    timeout = True
                time.sleep(0.3)

            exit_code = proc.returncode
            stdout = stdout_path.read_text("utf-8", errors="replace")
            stderr = stderr_path.read_text("utf-8", errors="replace")
            full_output = stdout + stderr

            if verbose:
                print(full_output.rstrip())
                print(f"\n{'-' * 10} {desc} - exit:{exit_code:#x} {'-' * 10}")

            if timeout:
                return 124, "TIMEOUT", f"After {timeout_sec}s", full_output

            return exit_code, "DONE", f"Exit code: {exit_code:#x}", full_output

        except Exception as exc:
            stdout = stdout_path.read_text("utf-8", errors="replace")
            stderr = stderr_path.read_text("utf-8", errors="replace")
            full_output = stdout + stderr

            if verbose:
                print(f"Failed to run Godot: {exc}")
                print(full_output.rstrip())
            return 1, "EXCEPTION", f"{exc}", full_output


def pre_import_project(godot_bin: Path):
    if not verbose:
        print("→ Pre-Import", end=" ", flush=True)

    args = ["--path", str(PROJECT_DIR), "--import", "--headless"]
    exit_code, strcode, msg, output = run_godot(args, "Pre-import", str(godot_bin), timeout_sec=IMPORT_TIMEOUT_SEC)
    if not verbose:
        # Show only summary / important parts
        lines = output.splitlines()
        filtered = filter_output(lines)
        if filtered:
            print("\n".join(filtered))

        print(f"[ {strcode} ]", end=" ")
        print(f"- {msg}" if msg else "")
    return exit_code != 0


def run_integration_tests(editor_bin: Path) -> bool:
    print("→ Unit/Integration Tests", end=" ", flush=True)

    args = ["--path", str(PROJECT_DIR), "--debug", "--headless", "--quit"]
    exitcode, strcode, msg, output = run_godot(args, "Unit/Integration tests", str(editor_bin))

    def is_successful(output_text: str) -> bool:
        return END_MARKER in output_text and PASSED_MARKER in output_text and FAILED_MARKER not in output_text

    if not verbose:
        print(f"[ {strcode} ]", end=" ")
        print(f"- {msg}" if msg else "")

    if exitcode == 124:
        print("> Unit phase: TIMEOUT")
        return False
    elif not is_successful(output):
        print("> Unit phase: FAILED")
        return False
    else:
        return True


def generate_extension_docs(editor: Path) -> bool:
    print("> GDExtension XML DocGen", end=" ", flush=True)

    doc_path = (PROJECT_DIR.parent / "doc_classes").resolve()
    # Expected files based on test/src classes
    expected_files = [
        "Example.xml",
        "ExampleAbstractBase.xml",
        "ExampleBase.xml",
        "ExampleChild.xml",
        "ExampleConcrete.xml",
        "ExampleMin.xml",
        "ExamplePrzykład.xml",
        "ExampleRef.xml",
        "ExampleRuntime.xml",
        "ExampleVirtual.xml",
    ]

    # Run from inside project/ (demo/), pointing --doctool at./
    args = [
        "--path",
        str(PROJECT_DIR),
        "--doctool",
        "..",
        "--gdextension-docs",
        "--headless",
        "--quit",
    ]
    exitcode, strcode, msg, output = run_godot(args, "GDExtension XML DocGen", str(editor))

    # print the completion of the non-verbose line.
    if not verbose:
        print(f"[ {strcode} ]", end=" ")
        print(f"- {msg}" if msg else "")

    if strcode == "TIMEOUT":
        if verbose:
            print("> DocGen phase: TIMEOUT")
        return False

    if doc_path.exists():
        xml_files = [f.name for f in doc_path.glob("*.xml")]
        missing = [f for f in expected_files if f not in xml_files]
        if missing:
            print(f"> DocGen phase: FAILED (Missing files: {', '.join(missing)})")
            return False

        if len(xml_files) > 0:
            if verbose:
                print(f"> DocGen doc_classes/ created at: {doc_path} ({len(xml_files)} XML files)")
                for file in doc_path.glob("*.xml"):
                    print(file)
            return True
        if verbose:
            print("> Warning: DocGen Command succeeded but no doc_classes/*.xml found")
        return False
    else:
        print("> DocGen phase: FAILED (Directory not found)")
        return False


def cleanup_docs():
    doc_path = (PROJECT_DIR.parent / "doc_classes").resolve()
    if doc_path.exists():
        try:
            shutil.rmtree(doc_path)
            print("> Cleaned doc_classes [ DONE ]")
        except OSError:
            if verbose:
                print(f"> Failed to remove {doc_path}")


# ----------------------------------------------
# Main
# ----------------------------------------------
def main():
    global verbose

    parser = argparse.ArgumentParser(description="Run godot-cpp test suite")
    parser.add_argument(
        "--tests-only",
        action="store_const",
        const="unit",
        dest="mode",
        help="Only run the integration tests (skip doc xml generation)",
    )
    parser.add_argument(
        "--docs-only",
        action="store_const",
        const="docs",
        dest="mode",
        help="Only generate GDExtension XML documentation (skip tests)",
    )
    parser.add_argument("--verbose", action="store_true", default=False, help="Show full unfiltered Godot output")
    parser.add_argument(
        "--quiet", action="store_true", default=False, help="Only exit code (0=success, >0=failure); no output"
    )
    parser.add_argument(
        "--godot-test-versions",
        type=str,
        default="",
        help="Space-separated list of Godot versions to download and test",
    )
    parser.add_argument(
        "--godot-test-arch",
        type=str,
        default="",
        help="Architecture for downloading Godot (e.g., linux.x86_64, win64.exe, macos.universal)",
    )
    args = parser.parse_args()

    # store a reference to print
    original_print = builtins.print

    mode = args.mode or "full"
    verbose = args.verbose

    if args.quiet:

        def silent(*_args, **_kwargs):
            pass

        builtins.print = silent
    else:
        builtins.print = original_print  # restore just in case

    if args.quiet and args.verbose:
        print("--quiet takes precedence over --verbose", file=sys.stderr)
        verbose = False

    versions = args.godot_test_versions.split()
    arch = args.godot_test_arch

    main_version = os.environ.get("GODOT_TEST_VERSION", "master")
    if main_version != "master":
        if main_version not in versions:
            versions.insert(0, main_version)

    if not versions or main_version == "master":
        if None not in versions:
            versions.insert(0, None)

    overall_success = True

    results = []  # list of dicts for table + JSON

    for version in versions:
        global GODOT_EDITOR, GODOT_RELEASE, GODOT_DEBUG
        if version:
            print(f"--- Testing against Godot {version} ({arch}) ---")
            godot_bin = download_godot(version, arch)
            if not godot_bin:
                overall_success = False
                record_test_result(results, version, False, 0)
                continue

            GODOT_EDITOR = str(godot_bin)
            GODOT_RELEASE = str(godot_bin)
            GODOT_DEBUG = str(godot_bin)
        else:
            discover_artifacts()

        editor_bin: Path = Path.cwd() / PORTABLE_EDITOR
        print(f"editor:           {GODOT_EDITOR}")
        print(f"template_release: {GODOT_RELEASE}")
        print(f"template_debug:   {GODOT_DEBUG}")
        print(f"Project:          {PROJECT_DIR}")
        print(f"Mode:             {mode}")
        print(f"Verbose:          {verbose}\n")

        start_time = time.time()

        setup_temp_portable_godot()
        _ = cleanup_godot_cache()
        _ = pre_import_project(editor_bin)

        success = True
        # Perform Integration Testing
        if mode in ("unit", "full") and success:
            success = run_integration_tests(editor_bin)

        if mode in ("docs", "full") and success:
            success = generate_extension_docs(editor_bin)

        cleanup_temp_portable()
        cleanup_docs()

        duration = int(time.time() - start_time)
        record_test_result(results, version, success, duration)

        if not success:
            overall_success = False

        print("-" * 80)
        status = "PASSED" if success else "FAILED"
        print(f"TEST SUITE ({version or 'master'}) {status} - took {duration}s")

    # --- Summary table and metrics artifact ---
    summary_path = os.environ.get("GITHUB_STEP_SUMMARY")
    if summary_path and results:
        try:
            with open(summary_path, "a", encoding="utf-8") as f:
                platform = os.environ.get("RUNNER_OS", "unknown")
                f.write(f"\n## Test Results - {platform} ({os.environ.get('RUNNER_OS', 'unknown')})\n\n")
                f.write("| Godot Version | Status     | Duration (s) |\n")
                f.write("|---------------|------------|--------------|\n")
                for r in results:
                    f.write(f"| {r['godot_version']:13} | {r['status']:10} | {r['duration_seconds']:12} |\n")
        except Exception:
            pass  # ignore summary write failures

    # Write JSON artifact for historical tracking
    metrics_path = SCRIPT_DIR / "test-metrics.json"
    try:
        import json

        with open(metrics_path, "w", encoding="utf-8") as f:
            json.dump(
                {
                    "timestamp": time.strftime("%Y-%m-%d %H:%M:%S UTC", time.gmtime()),
                    "platform": os.environ.get("RUNNER_OS", "unknown"),
                    "runner": os.environ.get("RUNNER_NAME", "unknown"),
                    "results": results,
                },
                f,
                indent=2,
            )
    except Exception:
        pass

    builtins.print = original_print
    sys.exit(0 if overall_success else 3)


if __name__ == "__main__":
    main()
