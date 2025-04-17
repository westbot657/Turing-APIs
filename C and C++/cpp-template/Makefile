# Makefile for C++ Template Project

# Compiler settings
CXX = clang++
CXXFLAGS = --target=wasm32-unknown-unknown -nostdlib -O2 -fvisibility=hidden -fno-exceptions -fno-rtti -ffreestanding


# Linker settings
LD = wasm-ld
LDFLAGS = --no-entry --export=on_load --export=on_update --export=on_exit --allow-undefined -O2

# Directories
CPP_API_DIR = ../turing-api-cpp
CPP_API_INCLUDE_DIR = $(CPP_API_DIR)/include
CPP_API_LIB_DIR = $(CPP_API_DIR)/build
INTERNAL_DIR = ../internal/src
BUILD_DIR = build

# Source files
SRC_FILES = main.cpp
OBJ_FILES = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# API libraries
CPP_API_LIB = $(CPP_API_LIB_DIR)/libturing-api-cpp.a

# Include paths
INCLUDES = -I$(CPP_API_INCLUDE_DIR) -I$(INTERNAL_DIR)

# Output file
WASM_FILE = build/script.wasm

# Targets
.PHONY: all clean cpp_api

all: dirs cpp_api $(WASM_FILE)

dirs:
	mkdir -p $(BUILD_DIR)

cpp_api:
	$(MAKE) -C $(CPP_API_DIR)

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Link WebAssembly module
$(WASM_FILE): $(OBJ_FILES) $(CPP_API_LIB)
	$(LD) $(LDFLAGS) $(OBJ_FILES) $(CPP_API_LIB) -o $@
	
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(WASM_FILE)