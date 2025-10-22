# Define Godot executable (uses environment variable if set, else defaults to 'godot')
$GODOT = if ($env:GODOT) { $env:GODOT } else { 'godot' }

$END_STRING = "==== TESTS FINISHED ===="
$FAILURE_STRING = "******** FAILED ********"
$HAS_FAILURE = 0

# Function to filter spam from output
function Filter-Output {
    param([string[]]$Lines)
    $Lines | ForEach-Object { $_.TrimEnd() } | Where-Object {
        $_ -notmatch "Narrowing conversion" -and
        $_ -notmatch "at:\s+GDScript::reload" -and
        $_ -notmatch "\[\s*\d+%\s*\]" -and
        $_ -notmatch "first_scan_filesystem" -and
        $_ -notmatch "loading_editor_layout"
    }
}

# Run Godot and capture output and exit code
try {
    $OUTPUT = & $GODOT --path project --debug --headless --quit 2>&1
    $ERRCODE = $LASTEXITCODE
}
catch {
    $OUTPUT = $_.Exception.Message
    $ERRCODE = 1
}

# Output the results
Write-Output $OUTPUT
Write-Output ""

# Check if tests completed
if (-not ($OUTPUT -match [regex]::Escape($END_STRING))) {
    $HAS_FAILURE += 1
}

# Check for test failures
if ($OUTPUT -match [regex]::Escape($FAILURE_STRING)) {
    $HAS_FAILURE += 1
}

# Lock file path (relative to project dir)
$LOCK_PATH = "project/test_reload_lock"

# Delete lock file before reload test if it exists
Remove-Item -Path $LOCK_PATH -Force -ErrorAction SilentlyContinue

# Run Godot and capture output and exit code
try {
    $OUTPUT = & $GODOT -e --path project --scene reload.tscn --headless --debug test_reload 2>&1
    $ERRCODE = $LASTEXITCODE
}
catch {
    $OUTPUT = $_.Exception.Message
    $ERRCODE = 1
}

# Filter and output the results
$FilteredOutput = Filter-Output -Lines ($OUTPUT -split "`n")
Write-Output ($FilteredOutput -join "`n")
Write-Output ""

# Check for test failures
if ($OUTPUT -match [regex]::Escape($FAILURE_STRING)) {
    $HAS_FAILURE += 1
}

# Lock file path (relative to project dir)
$LOCK_PATH = "project/test_reload_lock"

# Delete lock file before reload test if it exists
Remove-Item -Path $LOCK_PATH -Force -ErrorAction SilentlyContinue

if ($HAS_FAILURE -gt 0 ){
    Write-Output "ERROR: Tests failed to complete"
    exit 1
}

# Success!
exit 0
