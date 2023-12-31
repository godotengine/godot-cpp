#!/bin/bash

GODOT=${GODOT:-godot}

END_STRING="==== TESTS FINISHED ===="
FAILURE_STRING="******** FAILED ********"

# Import to get GDExtension library working
$GODOT --headless --path project --export-pack '<null>' /dev/null

OUTPUT=$($GODOT --path project --debug --headless --quit)
ERRCODE=$?

echo "$OUTPUT"
echo

if ! echo "$OUTPUT" | grep -e "$END_STRING" >/dev/null; then
    echo "ERROR: Tests failed to complete"
    exit 1
fi

if echo "$OUTPUT" | grep -e "$FAILURE_STRING" >/dev/null; then
    exit 1
fi

# Success!
exit 0
