#!/bin/bash
# create_static_lib.sh - compile all .c files and pack them into liball.a
set -euo pipefail

# Remove old library if any
rm -f liball.a

# Compile each .c to .o with the required flags
for src in *.c; do
  [ -e "${src}" ] || continue
  gcc -c -Wall -Wextra -Werror -pedantic -std=gnu89 "${src}"
done

# Create static library from all object files
ar rcs liball.a *.o

# Clean up object files
rm -f *.o
