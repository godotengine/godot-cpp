#!/bin/bash

USAGE_STRING="Usage: $0 plist_path --entry CFBundleExecutable=executable [--entry key=value]..."

PLIST_PATH=""
PLIST_ENTRIES=()

# Parse the command line arguments.
while [[ $# -gt 0 ]]; do
    case $1 in
        --entry)
            IFS='=' read -r key value <<< "$2"
            # Replace if key exists, otherwise add new key-value.
            found=false
            for ((i=0; i<${#PLIST_ENTRIES[@]}; i++)); do
                if [[ "${PLIST_ENTRIES[i]}" =~ ^$key= ]]; then
                    PLIST_ENTRIES[i]="$key=$value"
                    found=true
                    break
                fi
            done
            if [ "$found" = false ]; then
                PLIST_ENTRIES+=("$key=$value")
            fi
            shift 2
            ;;
        *)
            # Assume positional argument is the plist path.
            if [ -n "$PLIST_PATH" ]; then
                # Cannot generate more than one plist; this was likely an error.
                echo "$USAGE_STRING"
                exit 1
            fi
            PLIST_PATH="$1"
            shift
            ;;
    esac
done

# Extract known keys from PLIST_ENTRIES, for defaults and mandatory arguments.
for ((i=0; i<${#PLIST_ENTRIES[@]}; i++)); do
    IFS='=' read -r key value <<< "${PLIST_ENTRIES[$i]}"
    case $key in
        CFBundleInfoDictionaryVersion)
            CFBundleInfoDictionaryVersion="$value"
            ;;
        CFBundlePackageType)
            CFBundlePackageType="$value"
            ;;
        CFBundleName)
            CFBundleName="$value"
            ;;
        CFBundleExecutable)
            CFBundleExecutable="$value"
            ;;
        CFBundleIdentifier)
            CFBundleIdentifier="$value"
            ;;
        CFBundleVersion)
            CFBundleVersion="$value"
            ;;
        CFBundleShortVersionString)
            CFBundleShortVersionString="$value"
            ;;
    esac
done

# Check for mandatory arguments.
if [ -z "$PLIST_PATH" ] || [ -z "$CFBundleExecutable" ]; then
    echo "$USAGE_STRING"
    exit 1
fi

# Add defaults for missing arguments.
if [ -z "$CFBundleInfoDictionaryVersion" ]; then
  CFBundleInfoDictionaryVersion="6.0"
  PLIST_ENTRIES+=("CFBundleInfoDictionaryVersion=$CFBundleInfoDictionaryVersion")
fi
if [ -z "$CFBundlePackageType" ]; then
  CFBundlePackageType="FMWK"
  PLIST_ENTRIES+=("CFBundlePackageType=$CFBundlePackageType")
fi
if [ -z "$CFBundleName" ]; then
  CFBundleName="$CFBundleExecutable"
  PLIST_ENTRIES+=("CFBundleName=$CFBundleName")
fi
if [ -z "$CFBundleIdentifier" ]; then
  CFBundleIdentifier="com.example.$CFBundleName"
  PLIST_ENTRIES+=("CFBundleIdentifier=$CFBundleIdentifier")
fi
if [ -z "$CFBundleVersion" ]; then
  CFBundleVersion="1.0.0"
  PLIST_ENTRIES+=("CFBundleVersion=$CFBundleVersion")
fi
if [ -z "$CFBundleShortVersionString" ]; then
  CFBundleShortVersionString="$CFBundleVersion"
  PLIST_ENTRIES+=("CFBundleShortVersionString=$CFBundleShortVersionString")
fi

# Ensure the directory exists.
mkdir -p "$(dirname "$PLIST_PATH")"

# Create the Info.plist file.
{
echo '<?xml version="1.0" encoding="UTF-8"?>'
echo '<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">'
echo '<plist version="1.0">'
echo '<dict>'

for ((i=0; i<${#PLIST_ENTRIES[@]}; i++)); do
    IFS='=' read -r key value <<< "${PLIST_ENTRIES[$i]}"
    if [[ -n "$value" ]]; then
        echo "    <key>$key</key>"
        echo "    <string>$value</string>"
    fi
done

echo '</dict>'
echo '</plist>'
} > "$PLIST_PATH"

# Confirm Info.plist was created.
if [ -s "$PLIST_PATH" ]; then
    echo "$PLIST_PATH"
else
    echo "Failed to create $PLIST_PATH."
    exit 1
fi
