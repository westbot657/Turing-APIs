# Makefile for Lua->C WebAssembly build with header dependency

# Compiler and linker
CC = clang
LD = wasm-ld

# Flags
CFLAGS = --target=wasm32-unknown-unknown -nostdlib -O2 -fvisibility=hidden -I../turing-api-lua
LDFLAGS = --no-entry --export=on_load --export=on_update --export=on_exit --allow-undefined -O2

# File paths
SRC_FILE = build/script.c
OBJ_FILE = build/script.o
WASM_FILE = build/script.wasm

# Targets
.PHONY: all clean

all: $(WASM_FILE)

$(OBJ_FILE): $(SRC_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(WASM_FILE): $(OBJ_FILE)
	$(LD) $(LDFLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILE) $(WASM_FILE)
