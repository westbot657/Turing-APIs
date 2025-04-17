@echo off
where zig >nul 2>nul
if errorlevel 1 (
  echo Please install zig.
  exit /b 1
)
mkdir build

zig c++ main.cpp -target wasm32-unknown-unknown -I../turing-api-cpp/include -I../internal/src --no-entry -O2 -o build/script.wasm
