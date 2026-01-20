#!/bin/pwsh
# Build script for C and C++ projects
$DIR = Split-Path -Parent $MyInvocation.MyCommand.Definition
meson setup build-debug --buildtype=debug --cross-file "$DIR/wasi-cross.txt"
meson compile -C build-debug

# create build directory if it doesn't exist
if (-not (Test-Path -Path "./build")) {
    New-Item -ItemType Directory -Path "./build" | Out-Null
}
cp ./build-debug/compile_commands.json ./build/compile_commands.json