# Low Level Programming - C

This repository contains foundational C programming exercises focusing on compilation, preprocessing, and basic output operations.

## Project: 0x00-hello_world

A collection of bash scripts and C programs demonstrating the C compilation process and basic programming concepts.

### Learning Objectives

- Understanding the C compilation pipeline (preprocessing, compilation, assembly, linking)
- Writing bash scripts to automate compilation tasks
- Using environment variables in scripts
- Basic C program structure and output operations
- Using different output functions (puts, printf)

### Files Included

1. **0-preprocessor** - Runs C file through preprocessor
2. **1-compiler** - Compiles C file to object file (.o)
3. **2-assembler** - Generates assembly code (.s)
4. **3-name** - Compiles C file to executable named "cisfun"
5. **4-puts.c** - Program using puts() function
6. **5-printf.c** - Program using printf() function
7. **6-size.c** - Program displaying size of data types

### Usage

Each script reads the C filename from the `$CFILE` environment variable.

Example:
```bash
export CFILE=main.c
./0-preprocessor
```

### Requirements

- GCC compiler
- Bash shell
- Linux environment
