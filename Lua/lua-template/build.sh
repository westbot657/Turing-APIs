#!/bin/sh

set -e  # Exit on error

# Step 1: Generate C code from Nelua
echo "Generating C code from Nelua..."
nelua main.nelua --cflags="-m32" -o build/script.c

# Step 2: Build with Makefile
echo "Building with make..."
make
