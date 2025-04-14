# Makefile for Turing C API library

# Compiler settings
CC = clang
CFLAGS = --target=wasm32-unknown-unknown -nostdlib -O2 -fvisibility=hidden

# Directories
SRC_DIR = src
INCLUDE_DIR = include
INTERNAL_DIR = ../internal/src
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Include paths
INCLUDES = -I$(INCLUDE_DIR) -I$(INTERNAL_DIR)

# Output library file
LIB_FILE = $(BUILD_DIR)/libturing-api-c.a

# Targets
.PHONY: all clean

all: dirs $(LIB_FILE)

dirs:
	mkdir -p $(BUILD_DIR)

# Compile .c files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create static library
$(LIB_FILE): $(OBJ_FILES)
	llvm-ar rcs $@ $^

clean:
	rm -rf $(BUILD_DIR)