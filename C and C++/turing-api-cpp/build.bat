@echo off
where zig >nul 2>nul
if errorlevel 1 (
  echo Please install zig.
  exit /b 1
)
mkdir build

zig c++ src/turing_api_cpp.cpp -target wasm32-unknown-unknown -O2 -o build/script.wasm
