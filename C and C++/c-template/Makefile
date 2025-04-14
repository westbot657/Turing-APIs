# Makefile for C Template Project

# Compiler settings
CC = clang
CFLAGS = --target=wasm32-unknown-unknown -nostdlib -O2 -fvisibility=hidden

# Linker settings
LD = wasm-ld
LDFLAGS = --no-entry --export=on_load --export=on_update --export=on_exit --allow-undefined -O2

# Directories
API_DIR = ../turing-api-c
API_INCLUDE_DIR = $(API_DIR)/include
API_LIB_DIR = $(API_DIR)/build
INTERNAL_DIR = ../internal/src
BUILD_DIR = build

# Source files
SRC_FILES = main.c
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# API library
API_LIB = $(API_LIB_DIR)/libturing-api-c.a

# Include paths
INCLUDES = -I$(API_INCLUDE_DIR) -I$(INTERNAL_DIR)

# Output file
WASM_FILE = script.wasm

# Targets
.PHONY: all clean api

all: dirs api $(WASM_FILE)

dirs:
	mkdir -p $(BUILD_DIR)

api:
	$(MAKE) -C $(API_DIR)

# Compile .c files to .o files
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link WebAssembly module
$(WASM_FILE): $(OBJ_FILES) $(API_LIB)
	$(LD) $(LDFLAGS) $(OBJ_FILES) $(API_LIB) -o $@
	
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(WASM_FILE)