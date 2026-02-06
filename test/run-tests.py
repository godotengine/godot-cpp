#!/usr/bin/env python3
"""
run-tests.py - Robust test runner for godot-cpp test project (with temp portable Godot copy)

Usage:
    python run-tests.py [--unit-only | --TODO-only]    # default: full
"""

import argparse
import os
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import time
from pathlib import Path

# ──────────────────────────────────────────────
# Configuration
# ──────────────────────────────────────────────

ORIGINAL_GODOT = os.environ.get("GODOT", "godot")
PROJECT_DIR = Path("project").resolve()
GODOT_PROJECT = PROJECT_DIR

END_MARKER    = "==== TESTS FINISHED ===="
PASSED_MARKER = "******** PASSED ********"
FAILED_MARKER = "******** FAILED ********"

TIMEOUT_SEC       = 180
IMPORT_TIMEOUT_SEC = 30

FILTER_PATTERNS = [
    re.compile(r"Narrowing conversion"),
    re.compile(r"\[\s*\d+%\s*]"),
    re.compile(r"first_scan_filesystem"),
    re.compile(r"loading_editor_layout"),
]

TEMP_EXE_NAME = "godot-temp-portable.exe"
TEMP_MARKER_NAME = "_sc_"

PHASE_CLEANUP       = 10
PHASE_PRE_IMPORT    = 20
PHASE_UNIT_TESTS    = 30
PHASE_CLEANUP_TEMP  = 40   # not really a failure point, but for completeness

# ──────────────────────────────────────────────
# Portable Temp Copy Helpers
# ──────────────────────────────────────────────
def setup_temp_portable_godot(quiet:bool=False, verbose:bool=False) -> str:
    """Copy Godot exe + create marker for single-session portable mode."""
    original_path = Path(ORIGINAL_GODOT).resolve()
    if not original_path.is_file():
        if not quiet:
            print(f"Warning: Original Godot not found — using as-is.")
        return ORIGINAL_GODOT

    temp_exe = Path.cwd() / TEMP_EXE_NAME
    temp_marker = Path.cwd() / TEMP_MARKER_NAME

    try:
        if not quiet:
            print("→ Creating portable Godot", end=" ")
        shutil.copy2(original_path, temp_exe)
        temp_marker.touch(exist_ok=True)
        if not quiet:
            print("[ DONE ]")
        return str(temp_exe.absolute())
    except Exception as e:
        if not quiet:
            print("[ FAILED ]")
            print(f"Failed to setup temp portable Godot: {e}")
        return ORIGINAL_GODOT


def cleanup_temp_portable(quiet:bool=False, verbose:bool=False):
    """Remove temp exe, marker, and any editor_data folder."""
    temp_exe = Path.cwd() / TEMP_EXE_NAME
    temp_marker = Path.cwd() / TEMP_MARKER_NAME
    editor_data = Path.cwd() / "editor_data"

    cleaned = False
    for path in [temp_exe, temp_marker]:
        if path.exists():
            try:
                path.unlink()
                cleaned = True
                if verbose: print(f"Cleaned: {path}")
            except Exception as e:
                print(f"Warning: Could not delete {path}: {e}")

    if editor_data.exists():
        try:
            shutil.rmtree(editor_data)
            if verbose: print(f"Cleaned editor_data folder: {editor_data}")
        except Exception as e:
            if verbose: print(f"Warning: Could not delete editor_data: {e}")

    if not quiet and cleaned:
        print("→ Cleaned [ DONE ]")





# ──────────────────────────────────────────────
# Other Helpers
# ──────────────────────────────────────────────

def filter_output(lines: list[str], quiet:bool=False, verbose:bool=False) -> list[str]:
    if verbose:
        return [line.rstrip() for line in lines if line.strip()]  # just trim, keep everything
    # original quiet filtering
    result = []
    for line in lines:
        cleaned = line.rstrip()
        if not cleaned:
            continue
        if any(pat.search(cleaned) for pat in FILTER_PATTERNS):
            continue
        result.append(cleaned)
    return result

def is_successful(output: str) -> bool:
    has_end    = END_MARKER in output
    has_passed = PASSED_MARKER in output
    has_failed = FAILED_MARKER in output
    return has_end and has_passed and not has_failed

def cleanup_godot_cache(quiet:bool=False, verbose:bool=False):
    cache_dir = PROJECT_DIR / ".godot"
    if cache_dir.exists():
        if not quiet:
            print("→ Cleaning project cache", end=" ")
        try:
            shutil.rmtree(cache_dir, ignore_errors=True)
            if not quiet:
                print("[ DONE ]")
        except Exception as e:
            if verbose:
                print(f"Warning: Failed to clean .godot: {e}")
            elif not quiet:
                print("[ FAILED ]")

    cache_dir = PROJECT_DIR / ".godot"
    if cache_dir.exists():
        print(f"Cleaning project cache: {cache_dir}")
        try:
            shutil.rmtree(cache_dir, ignore_errors=True)
        except Exception as e:
            print(f"Warning: Failed to clean .godot: {e}")

def run_godot(
    args: list[str], desc: str, godot_bin: str, timeout_sec: int = TIMEOUT_SEC, quiet: bool = False,
    verbose: bool = False, phase_code_on_fail=None
) -> tuple[int, str, bool]:
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
            while proc.poll() is None:
                if time.time() - start > timeout_sec:
                    print(f"→ TIMEOUT after {timeout_sec}s – killing")
                    proc.send_signal(signal.SIGTERM)
                    time.sleep(1)
                    if proc.poll() is None:
                        proc.kill()
                    proc.wait()
                    return 124, "TIMEOUT", True
                time.sleep(0.5)

            exit_code = proc.returncode
            stdout = stdout_path.read_text("utf-8", errors="replace")
            stderr = stderr_path.read_text("utf-8", errors="replace")
            full_output = stdout + stderr

            # ── Output printing logic ──
            if verbose:
                print(full_output.rstrip())
            else:
                # In quiet mode: show only summary / important parts
                lines = full_output.splitlines()
                filtered = filter_output(lines, verbose=False)
                if filtered:
                    print("\n".join(filtered))
                else:
                    print("(no relevant output)")

            print(f"→ Exit code: {exit_code}")
            return exit_code, full_output, False

        except Exception as exc:
            msg = f"Failed to run Godot: {exc}"
            print(msg)
            return 1, msg, False

def pre_import_project(godot_bin:str, quiet:bool=False, verbose:bool=False):
    if verbose:
        print("\nPre-importing project (headless, short timeout)...")
    elif not quiet: print("→ Pre-import", end=" ")

    cleanup_godot_cache(quiet=quiet, verbose=verbose)

    args = ["--path", str(GODOT_PROJECT), "--import", "--headless"]
    exit_code, output, timed_out = run_godot(
        args, "Pre-import", godot_bin,
        timeout_sec=IMPORT_TIMEOUT_SEC,
        verbose=verbose, quiet=quiet
    )
    if timed_out or exit_code != 0:
        if verbose:
            print("→ Pre-import failed or timed out — continuing anyway")
        elif not quiet:
            print("[ CRASH/FAIL ]")
        return False, PHASE_PRE_IMPORT
    else:
        if verbose:
            print("→ Pre-import completed")
        elif not quiet:
            print("[ DONE ]")
        return True, 0


def run_tests(mode: str, godot_bin: str, quiet:bool=False, verbose:bool=False) -> bool:
    overall_success = True
    failed_phase = 0

    if not quiet:
        print("Preparing project...")
# ── One-time preparation ──
    if not quiet:
        print("\nPreparing project (one-time cleanup + pre-import)...")
        print("Preparing project...")

    ok, phase = pre_import_project(godot_bin, quiet=quiet, verbose=verbose) # Attempt import once (ignore failures)
    if not ok:
        return False   # early return — we'll set exit code higher up

    # No more cleanups after this point — let the cache persist

    if mode in ("unit", "full"):
        if not quiet: print("→ Unit / headless tests")

        args = ["--path", str(GODOT_PROJECT), "--debug", "--headless", "--quit"]
        exit_code, output, timed_out = run_godot(
            args, "Unit / headless tests", godot_bin,
            verbose=verbose, quiet=quiet )

        # Summary parsing still uses full output
        if timed_out:
            if not quiet: print("→ Unit phase: TIMEOUT")
            overall_success = False
            failed_phase = PHASE_UNIT_TESTS
        elif not is_successful(output):
            if not quiet:
                print("→ Unit phase: did NOT detect clean success")
            overall_success = False
            failed_phase = PHASE_UNIT_TESTS
        elif not quiet:
            # Show minimal success summary even in non-verbose
            lines = output.splitlines()
            for line in lines:
                if any(m in line for m in [END_MARKER, PASSED_MARKER]):
                    print(line.strip())
            print("→ Unit phase: [ PASSED ]")

        if verbose:
            # Optional: print a small reminder about the known error
            if "ExampleInternal" in output:
                print("  (known non-fatal warning about 'ExampleInternal' suppressed)")

    return overall_success

# ──────────────────────────────────────────────
# Main
# ──────────────────────────────────────────────
def main():
    parser = argparse.ArgumentParser(description="Run godot-cpp test suite (temp portable Godot)")
    parser.add_argument("--unit-only", action="store_const", const="unit", dest="mode")
    parser.add_argument("--verbose", action="store_true", default=False,
        help="Show full unfiltered Godot output")
    parser.add_argument("--quiet", action="store_true", default=False,
        help="Minimal output — only final exit code (for CI)")
    args = parser.parse_args()

    mode   = args.mode or "full"
    verbose = args.verbose
    quiet  = args.quiet

    # ── Early exit for quiet mode if we want ultra-minimal ──
    if quiet:
        # We'll suppress almost all prints later
        def qprint(*a, **kw): pass
        global print
        print = qprint   # monkey-patch print (crude but effective for this script)

    if quiet and verbose:
        print("Error: --quiet and --verbose are mutually exclusive", file=sys.stderr)
        sys.exit(1)

    print(f"Godot Executable: {ORIGINAL_GODOT}")
    print(f"Project:          {GODOT_PROJECT}")
    print(f"Mode:             {mode}")
    print(f"Verbose:          {verbose}\n")

    godot_bin = setup_temp_portable_godot(quiet=quiet)

    exit_code = 0
    try:
        success = run_tests(mode, godot_bin, verbose=verbose, quiet=quiet)
        if not success:
            exit_code = 3   # default unit failure; overridden in run_tests if earlier phase
    except Exception as e:
        print(f"Runner crashed: {e}", file=sys.stderr)
        exit_code = 1
    finally:
        cleanup_temp_portable(quiet=quiet, verbose=verbose)

    if not quiet:
        print("\n" + "═" * 40)
        status = "PASSED" if exit_code == 0 else f"FAILED (code {exit_code})"
        duration = f" - took {int(time.time() - start_time)}s" if 'start_time' in globals() else ""
        print(f"TEST SUITE {status}{duration}")

    sys.exit(exit_code)


if __name__ == "__main__":
    main()
