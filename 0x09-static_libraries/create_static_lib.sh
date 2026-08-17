#!/bin/bash
# create_static_lib.sh
# Compiles all .c files in the current directory (except _putchar.c if present)
# into object files and creates a static library liball.a

set -e

SRCFILES=("$(ls *.c 2>/dev/null)" )
# If no .c files, exit
if [ -z "${SRCFILES[0]}" ] || [ "${SRCFILES[0]}" = "" ]; then
  echo "No .c files found in $(pwd)"
  exit 1
fi

# Compile each .c into .o using required flags
for f in *.c; do
  if [ "$f" = "_putchar.c" ]; then
    # skip _putchar.c by convention; user should provide it separately
    continue
  fi
  gcc -c -Wall -Werror -Wextra -pedantic -std=gnu89 "$f"
done

# Create static library from all .o files
ar rcs liball.a *.o

# Optional: remove object files
rm -f *.o

echo "liball.a created"
