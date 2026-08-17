#!/bin/bash
# create_libmy.sh
# Compile selected .c files and create libmy.a static library
# This script compiles the expected source files with the required flags
# and produces libmy.a that contains the required symbols.

set -e

# Ensure we're in the directory where the script lives
cd "$(dirname "$0")"

# List the source files to include in libmy.a (order helps reproducibility)
SRCS=(
  "_putchar.c"
  "100-atoi.c"
  "0-isupper.c"
  "0-memset.c"
  "0-strcat.c"
  "1-isdigit.c"
  "1-memcpy.c"
  "1-strncat.c"
  "2-strchr.c"
  "2-strlen.c"
  "2-strncpy.c"
  "3-islower.c"
  "3-puts.c"
  "3-strcmp.c"
  "3-strspn.c"
  "4-isalpha.c"
  "4-strpbrk.c"
  "5-strstr.c"
  "6-abs.c"
  "9-strcpy.c"
)

# Check that each source file exists
for f in "${SRCS[@]}"; do
  if [ ! -f "$f" ]; then
    echo "Warning: source file $f not found in $(pwd)"
  fi
done

# Clean old object files and library
rm -f *.o libmy.a

# Compile each existing source file into an object file with strict flags
for f in "${SRCS[@]}"; do
  if [ -f "$f" ]; then
    gcc -c -Wall -Werror -Wextra -pedantic -std=gnu89 "$f"
  fi
done

# Create the static library libmy.a from the object files
ar rcs libmy.a *.o

# Show the archive contents for verification
echo "Created libmy.a containing:"
ar -t libmy.a

# Optional: show symbol table (nm may print many lines)
nm libmy.a | grep " T " || true

# Clean up object files
rm -f *.o

echo "libmy.a built successfully."
