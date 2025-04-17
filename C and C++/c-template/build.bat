@echo off
where zig >nul 2>nul
if errorlevel 1 (
  echo Please install zig.
  exit /b 1
)
mkdir build
zig cc main.c -target wasm32-freestanding ^
    -I../internal/src -I../turing-api-c/include/ ^
    -Wl,--no-entry ^
    -Wl,--export=on_load ^
    -Wl,--export=on_update ^
    -Wl,--export=on_exit ^
    -Wl,--allow-undefined ^
    -O2 -o build/script.wasm
