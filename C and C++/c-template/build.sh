#!/bin/bash

set -e

WASI_SDK=${WASI_SDK:-/opt/wasi-sdk}

$WASI_SDK/bin/clang \
    --target=wasm32-wasi \
    -I../turing-api-c/include \
    main.c \
    ../turing-api-c/src/turing_api_c.c \
    -o output.wasm \
    -O3 \
    -Wl,--export-all \
    -Wl,--no-entry

echo "Built output.wasm"
