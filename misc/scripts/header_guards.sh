#!/bin/bash

if [ ! -f "SConstruct" ]; then
  echo "Warning: This script is intended to be run from the root of the Godot repository."
  echo "Some of the paths checks may not work as intended from a different folder."
fi

files_invalid_guard=""

for file in $(find . -name "*.hpp" -print); do
  # Skip generated files.
  if [[ "$file" == "./gen/"* || "$file" == "./include/gen/"* ]]; then continue; fi
  # Skip the test project.
  if [[ "$file" == "./test/"* ]]; then continue; fi

  bname=$(basename $file .hpp)

  # NOTE: The "GODOT_CPP_" prefix is already used by the generated
  # bindings, so we can't use that. We'll use "GODOT_" instead.
  prefix="GODOT_"

  # ^^ is bash builtin for UPPERCASE.
  guard="${prefix}${bname^^}_HPP"

  # Replaces guards to use computed name.
  # We also add some \n to make sure there's a proper separation.
  sed -i $file -e "0,/ifndef/s/#ifndef.*/\n#ifndef $guard/"
  sed -i $file -e "0,/define/s/#define.*/#define $guard\n/"
  sed -i $file -e "$ s/#endif.*/\n#endif \/\/ $guard/"
  # Removes redundant \n added before, if they weren't needed.
  sed -i $file -e "/^$/N;/^\n$/D"

  # Check that first ifndef (should be header guard) is at the expected position.
  # If not it can mean we have some code before the guard that should be after.
  # "31" is the expected line with the copyright header.
  first_ifndef=$(grep -n -m 1 "ifndef" $file | sed 's/\([0-9]*\).*/\1/')
  if [[ "$first_ifndef" != "31" ]]; then
    files_invalid_guard+="$file\n"
  fi
done

if [[ ! -z "$files_invalid_guard" ]]; then
  echo -e "The following files were found to have potentially invalid header guard:\n"
  echo -e "$files_invalid_guard"
fi

diff=$(git diff --color)

# If no diff has been generated all is OK, clean up, and exit.
if [ -z "$diff" ] ; then
    printf "Files in this commit comply with the header guards formatting rules.\n"
    exit 0
fi

# A diff has been created, notify the user, clean up, and exit.
printf "\n*** The following differences were found between the code "
printf "and the header guards formatting rules:\n\n"
echo "$diff"
printf "\n*** Aborting, please fix your commit(s) with 'git commit --amend' or 'git rebase -i <hash>'\n"
exit 1
