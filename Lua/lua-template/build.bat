@echo off
where zig >nul 2>nul
if errorlevel 1 (
  echo Please install zig.
  exit /b 1
)
mkdir build

nelua main.nelua --cflags="-m32" -o build/script.c

zig cc build/script.c -target wasm32-unknown-unknown -O2 -o build/script.wasm
