#!/bin/pwsh
# Build script for C and C++ projects
$DIR = Split-Path -Parent $MyInvocation.MyCommand.Definition
meson setup build-release --buildtype=release --cross-file "$DIR/wasi-cross.txt"
meson compile -C build-release