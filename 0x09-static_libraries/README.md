# Static libraries exercise

This directory contains starter implementations (one function per file) for the "0x09. Static Libraries" project. The repository intentionally does not include _putchar.c — provide your own _putchar implementation when building the final static library.

Usage:

1. Place your _putchar.c in this directory (not included in this repo).
2. Run ./create_static_lib.sh to compile the .c files and create liball.a
3. Link with -L. -lall when compiling your main program.

All code is written to compile with:
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89

Files:
- main.h: common prototypes
- create_static_lib.sh: build script
- Several .c files implementing the required functions (one function per file)
