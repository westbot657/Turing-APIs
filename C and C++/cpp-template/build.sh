#!/bin/bash

set -e

WASI_SDK=${WASI_SDK:-/opt/wasi-sdk}

$WASI_SDK/bin/clang++ \
    --target=wasm32-wasi \
    -I../turing-api-cpp/include \
    main.cpp \
    ../turing-api-cpp/src/turing_api_cpp.cpp \
    -o output.wasm \
    -O3 \
    -std=c++17 \
    -Wl,--export-all \
    -Wl,--no-entry

echo "Built output.wasm"
