#!/bin/pwsh
# Build script for C and C++ projects
$DIR = Split-Path -Parent $MyInvocation.MyCommand.Definition
meson setup build-debug --buildtype=debug --cross-file "$DIR/wasi-cross.txt"
meson compile -C build-debug