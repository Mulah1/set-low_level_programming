#!/bin/bash
# create_static_lib.sh - compile all .c files and pack them into liball.a
# This script compiles every .c in the current directory using the
# required flags and creates liball.a.

set -e

# Enable nullglob so that the array is empty if no matches
shopt -s nullglob
cfiles=( *.c )

if [ ${#cfiles[@]} -eq 0 ]; then
  echo "No .c files found in $(pwd)"
  exit 1
fi

# Compile all .c files into .o with required flags
gcc -c -Wall -Werror -Wextra -pedantic -std=gnu89 "${cfiles[@]}"

# Create static library from all object files
ar rcs liball.a *.o

# Clean up object files
rm -f *.o

echo "liball.a created"
