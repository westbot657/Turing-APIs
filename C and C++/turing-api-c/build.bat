@echo off
where zig >nul 2>nul
if errorlevel 1 (
  echo Please install zig.
  exit /b 1
)
mkdir build

zig cc src/turing_api_c.c -target wasm32-unknown-unknown --no-entry -O2 -o build/script.wasm
