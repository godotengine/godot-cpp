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
from pathlib import Path
from typing import List, Tuple

# ──────────────────────────────────────────────
# Configuration
# ──────────────────────────────────────────────

ORIGINAL_GODOT = os.environ.get("GODOT", "godot")
PROJECT_DIR = Path("project").resolve()
GODOT_PROJECT = PROJECT_DIR

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

TEMP_EXE_NAME = "godot-temp-portable.exe"
TEMP_MARKER_NAME = "_sc_"

PHASE_CLEANUP = 10
PHASE_PRE_IMPORT = 20
PHASE_UNIT_TESTS = 30

# ──────────────────────────────────────────────
# Helpers
# ──────────────────────────────────────────────


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


# ──────────────────────────────────────────────
# Portable Godot
# ──────────────────────────────────────────────


def setup_temp_portable_godot(original_path: Path):
    if not original_path.is_file():
        print("Warning: Original Godot not found — using as-is.")
        return ORIGINAL_GODOT

    temp_exe = Path.cwd() / TEMP_EXE_NAME
    temp_marker = Path.cwd() / TEMP_MARKER_NAME

    try:
        print("→ Creating portable Godot", end=" ")
        shutil.copy2(original_path, temp_exe)
        temp_marker.touch(exist_ok=True)
        print("[ DONE ]")
        return str(temp_exe.absolute())
    except OSError:
        print("[ FAILED ]")
        return ORIGINAL_GODOT


def cleanup_temp_portable(verbose: bool = False):
    temp_exe = Path.cwd() / TEMP_EXE_NAME
    temp_marker = Path.cwd() / TEMP_MARKER_NAME
    editor_data = Path.cwd() / "editor_data"

    cleaned = False
    for path in [temp_exe, temp_marker]:
        if path.exists():
            try:
                path.unlink()
                cleaned = True
            except OSError:
                if verbose:
                    print(f"→ Failed to remove {path}")
    if editor_data.exists():
        try:
            shutil.rmtree(editor_data)
            cleaned = True
        except OSError:
            if verbose:
                print("→ Failed to clean temporary editor_data directory")

    if cleaned:
        print("→ Cleaned [ DONE ]")


# ──────────────────────────────────────────────
# Cache & Run
# ──────────────────────────────────────────────


def cleanup_godot_cache(verbose: bool = False) -> bool:
    cache_dir = PROJECT_DIR / ".godot"
    if cache_dir.exists():
        print("→ Cleaning project cache", end=" ")
        try:
            shutil.rmtree(cache_dir, ignore_errors=True)
            print("[ DONE ]")
        except Exception as e:
            print(f"[ FAILED ] {e}")
            return False
    return True


def run_godot(
    args: List[str],
    desc: str,
    godot_bin: str,
    timeout_sec: int = TIMEOUT_SEC,
    verbose: bool = False,
) -> Tuple[int, str, str, str]:
    if verbose:
        print(f"\n{'─' * 10} {desc} {'─' * 10}")
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
                print(f"\n{'─' * 10} {desc} - exit:{exit_code:#x} {'─' * 10}")

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


def pre_import_project(godot_bin: str, verbose: bool = False):
    if not verbose:
        print("→ Pre-Import", end=" ", flush=True)

    args = ["--path", str(GODOT_PROJECT), "--import", "--headless"]
    exit_code, strcode, msg, output = run_godot(
        args, "Pre-import", godot_bin, timeout_sec=IMPORT_TIMEOUT_SEC, verbose=verbose
    )
    if not verbose:
        # Show only summary / important parts
        lines = output.splitlines()
        filtered = filter_output(lines)
        if filtered:
            print("\n".join(filtered))

        print(f"[ {strcode} ]", end=" ")
        print(f"- {msg}" if msg else "")
    return exit_code != 0


def run_integration_tests(godot_bin: str, verbose: bool = False) -> bool:
    print("→ Unit/Integration Tests", end=" ", flush=True)

    args = ["--path", str(GODOT_PROJECT), "--debug", "--headless", "--quit"]
    exitcode, strcode, msg, output = run_godot(args, "Unit/Integration tests", godot_bin, verbose=verbose)

    def is_successful(output: str) -> bool:
        return END_MARKER in output and PASSED_MARKER in output and FAILED_MARKER not in output

    if not verbose:
        print(f"[ {strcode} ]", end=" ")
        print(f"- {msg}" if msg else "")

    if exitcode == 127:
        print("→ Unit phase: TIMEOUT")
        return False
    elif not is_successful(output):
        print("→ Unit phase: FAILED")
        return False
    else:
        return True


def generate_extension_docs(godot_bin: str, verbose: bool = False) -> bool:
    print("→ GDExtension XML DocGen", end=" ", flush=True)

    # Run from inside project/ (demo/), pointing --doctool at ../
    args = [
        "--path",
        str(PROJECT_DIR),
        "--doctool",
        "..",
        "--gdextension-docs",
        "--headless",
        "--quit",
    ]
    exitcode, strcode, msg, output = run_godot(args, "GDExtension XML DocGen", godot_bin, verbose=verbose)

    # print the completion of the non verbose line.
    if not verbose:
        print(f"[ {strcode} ]", end=" ")
        print(f"- {msg}" if msg else "")

    if strcode == "TIMEOUT":
        if verbose:
            print("→ DocGen phase: TIMEOUT")
        return False

    doc_path = (PROJECT_DIR.parent / "doc_classes").resolve()
    if doc_path.exists():
        xml_files = List(doc_path.glob("*.xml"))
        if len(xml_files) > 0:
            if verbose:
                print(f"→ DocGen doc_classes/ created at: {doc_path} ({len(xml_files)} XML files)")
                for file in xml_files:
                    print(file)
            return True
        if verbose:
            print("→ Warning: DocGen Command succeeded but no doc_classes/*.xml found")
        return False
    else:
        print("→ DocGen phase: FAILED")
        return False


# ──────────────────────────────────────────────
# Main
# ──────────────────────────────────────────────


def main():
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
        "--editor-bin",
        default=ORIGINAL_GODOT,
        help="Path to Godot editor binary for --doctool (default: same as test Godot)",
    )
    args = parser.parse_args()

    # store a reference to print
    original_print = builtins.print

    godot_path = Path(ORIGINAL_GODOT).resolve()
    editor_path = Path(args.editor_bin).resolve()
    # TODO test godot bin to make sure its ok.

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

    start_time = time.time()

    print(f"Godot Executable: {ORIGINAL_GODOT}")
    print(f"Project:          {GODOT_PROJECT}")
    print(f"Mode:             {mode}")
    print(f"Verbose:          {verbose}\n")

    godot_bin = setup_temp_portable_godot(godot_path)

    _ = cleanup_godot_cache(verbose=verbose)
    _ = pre_import_project(godot_bin, verbose=verbose)
    # NOTE: the above aren't strictly necessary , and the import will always fail anyway.

    success = True
    if mode in ("unit", "full") and success:
        success = run_integration_tests(godot_bin, verbose=verbose)

    if mode in ("docs", "full") and success:
        editor_bin = godot_bin if editor_path == godot_path else setup_temp_portable_godot(editor_path)
        success = generate_extension_docs(editor_bin, verbose=verbose)

    cleanup_temp_portable()

    duration = int(time.time() - start_time)

    print("" + "-" * 80)
    status = "PASSED" if success else "FAILED"
    print(f"TEST SUITE {status} - took {duration}s")

    builtins.print = original_print
    sys.exit(0 if success else 3)


if __name__ == "__main__":
    main()
