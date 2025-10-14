#!/bin/bash

set -e

WASI_SDK=${WASI_SDK:-/opt/wasi-sdk}

nelua --cc=clang \
    --cflags="--target=wasm32-wasi -I../turing-api-lua" \
    --ldflags="--target=wasm32-wasi -Wl,--export-all -Wl,--no-entry" \
    --cache-dir=./cache \
    --path="../turing-api-lua/?.nelua" \
    --binary \
    --output=output.wasm \
    main.nelua

echo "Built output.wasm"
