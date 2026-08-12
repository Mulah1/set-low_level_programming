#!/bin/bash
# create_static_lib.sh - compile all .c files and pack them into liball.a
set -euo pipefail

# Remove old library if any
rm -f liball.a

# Enable nullglob so that the pattern expands to empty when no matches
shopt -s nullglob

# Collect C source files
c_files=( *.c )

# Exit if there are no C files
[ ${#c_files[@]} -gt 0 ] || exit 0

# Compile all .c files to .o with the required flags (do NOT treat warnings as errors)
gcc -c -Wall -Wextra -pedantic -std=gnu89 "${c_files[@]}"

# Create static library from all object files
ar rcs liball.a *.o

# Clean up object files
rm -f *.o
