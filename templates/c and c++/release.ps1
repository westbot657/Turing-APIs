#!/bin/pwsh
# Build script for C and C++ projects
$DIR = Split-Path -Parent $MyInvocation.MyCommand.Definition
meson setup build-release --buildtype=release --cross-file "$DIR/wasi-cross.txt"
meson compile -C build-release

# create build directory if it doesn't exist
if (-not (Test-Path -Path "./build")) {
    New-Item -ItemType Directory -Path "./build" | Out-Null
}
cp ./build-release/compile_commands.json ./build/compile_commands.json