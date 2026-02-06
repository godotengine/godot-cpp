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
    re.compile(r"\[\s*\d+%\s*\]"),
    re.compile(r"first_scan_filesystem"),
    re.compile(r"loading_editor_layout"),
]

TEMP_EXE_NAME = "godot-temp-portable.exe"
TEMP_MARKER_NAME = "_sc_"

# ──────────────────────────────────────────────
# Portable Temp Copy Helpers
# ──────────────────────────────────────────────

def setup_temp_portable_godot() -> str:
    """Copy Godot exe + create marker for single-session portable mode."""
    original_path = Path(ORIGINAL_GODOT).resolve()
    if not original_path.is_file():
        print(f"Warning: Original Godot not found at '{original_path}' — using as-is.")
        return ORIGINAL_GODOT

    temp_exe = Path.cwd() / TEMP_EXE_NAME
    temp_marker = Path.cwd() / TEMP_MARKER_NAME

    try:
        print(f"Creating temporary portable copy: {temp_exe}")
        shutil.copy2(original_path, temp_exe)

        print(f"Creating portable marker: {temp_marker}")
        temp_marker.touch(exist_ok=True)

        # Return path to temp exe
        return str(temp_exe.absolute())

    except Exception as e:
        print(f"Failed to setup temp portable Godot: {e}")
        print("Falling back to original executable (may pollute system data dirs)")
        return ORIGINAL_GODOT


def cleanup_temp_portable():
    """Remove temp exe, marker, and any editor_data folder."""
    temp_exe = Path.cwd() / TEMP_EXE_NAME
    temp_marker = Path.cwd() / TEMP_MARKER_NAME
    editor_data = Path.cwd() / "editor_data"

    for path in [temp_exe, temp_marker]:
        if path.exists():
            try:
                path.unlink()
                print(f"Cleaned: {path}")
            except Exception as e:
                print(f"Warning: Could not delete {path}: {e}")

    if editor_data.exists():
        try:
            shutil.rmtree(editor_data)
            print(f"Cleaned editor_data folder: {editor_data}")
        except Exception as e:
            print(f"Warning: Could not delete editor_data: {e}")


# ──────────────────────────────────────────────
# Other Helpers (unchanged from previous)
# ──────────────────────────────────────────────

def filter_output(lines: list[str]) -> list[str]:
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


def cleanup_godot_cache():
    cache_dir = PROJECT_DIR / ".godot"
    if cache_dir.exists():
        print(f"Cleaning project cache: {cache_dir}")
        try:
            shutil.rmtree(cache_dir, ignore_errors=True)
        except Exception as e:
            print(f"Warning: Failed to clean .godot: {e}")


def run_godot(args: list[str], desc: str, godot_bin: str, timeout_sec: int = TIMEOUT_SEC) -> tuple[int, str, bool]:
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

            print(full_output.rstrip())
            print(f"→ Exit code: {exit_code}")
            return exit_code, full_output, False

        except Exception as exc:
            msg = f"Failed to run Godot: {exc}"
            print(msg)
            return 1, msg, False


def pre_import_project(godot_bin: str):
    print("\nPre-importing project (headless, short timeout)...")
    cleanup_godot_cache()

    args = ["--path", str(GODOT_PROJECT), "--import", "--headless"]
    exit_code, output, timed_out = run_godot(args, "Pre-import", godot_bin, timeout_sec=IMPORT_TIMEOUT_SEC)

    if timed_out or exit_code != 0:
        print("→ Pre-import failed/crashed — This is expected, continuing anyway")
    else:
        print("→ Pre-import completed")

def run_tests(mode: str, godot_bin: str) -> bool:
    overall_success = True

    # ── One-time preparation ──
    print("\nPreparing project (one-time cleanup + pre-import)...")
    cleanup_godot_cache()           # Clean once at start

    pre_import_project(godot_bin)   # Attempt import once (ignore failures)

    # No more cleanups after this point — let the cache persist

    if mode in ("unit", "full"):
        args = ["--path", str(GODOT_PROJECT), "--debug", "--headless", "--quit"]
        _, output, timed_out = run_godot(args, "Unit / headless tests", godot_bin)

        filtered = filter_output(output.splitlines())
        print("\nFiltered output:")
        print("\n".join(filtered))

        if timed_out:
            print("→ Unit phase: TIMEOUT")
            overall_success = False
        elif not is_successful(output):
            print("→ Unit phase: did NOT detect clean success")
            overall_success = False
        else:
            print("→ Unit phase: detected PASSED")

    return overall_success


# ──────────────────────────────────────────────
# Main
# ──────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description="Run godot-cpp test suite (temp portable Godot)")
    parser.add_argument("--unit-only", action="store_const", const="unit", dest="mode")
    args = parser.parse_args()

    mode = args.mode or "full"

    print(f"Original Godot: {ORIGINAL_GODOT}")
    print(f"Project:        {GODOT_PROJECT}")
    print(f"Mode:           {mode}\n")

    # Setup temp portable copy
    godot_bin = setup_temp_portable_godot()

    try:
        all_passed = run_tests(mode, godot_bin)
    finally:
        # Always cleanup temp files
        cleanup_temp_portable()

    print("\n" + "═" * 40)
    if all_passed:
        print("TEST SUITE PASSED")
        sys.exit(0)
    else:
        print("TEST SUITE FAILED")
        sys.exit(1)


if __name__ == "__main__":
    main()
