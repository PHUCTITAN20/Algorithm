# Algorithm Repository

This repository contains sample source code for practicing algorithms and data structures using C and C++.

## Directory Overview

- **agorithm/** – Small C++ programs demonstrating sorting algorithms such as bubble sort, insertion sort and quick sort. Additional practice files are also included. The `output` folder in this directory stores precompiled binaries and a `data.txt` used by some examples.
- **DATA STRUCTURE/** – Collection of data‑structure exercises written mostly in C. Subfolders group code for binary search trees, generic binary tree implementations, linked lists, stacks and queues, and programs managing student lists. At the top level of this directory are standalone `.c` examples (`Cau_1.c`, `Cau_2.c`, …) illustrating fundamental list operations.

## Building Examples

A basic `Makefile` is provided to compile the sample programs. It uses `gcc` for C sources and `g++` for C++ sources and places the resulting binaries in a `bin/` directory. To build everything, run:

```bash
make
```

Individual files can also be compiled manually if desired. For example:

```bash
# Compile a C example
gcc 'DATA STRUCTURE/Cau_1.c' -o bin/Cau_1

# Compile a C++ example
g++ agorithm/BubbleSort.cpp -o bin/BubbleSort
```

Use `make clean` to remove all built binaries.
