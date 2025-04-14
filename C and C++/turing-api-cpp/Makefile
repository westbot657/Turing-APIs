# Makefile for Turing C++ API library

# Compiler settings
CXX = clang++
CXXFLAGS = --target=wasm32-unknown-unknown -nostdlib -O2 -fvisibility=hidden -fno-exceptions -fno-rtti

# Directories
SRC_DIR = src
INCLUDE_DIR = include
INTERNAL_DIR = ../internal/src
C_API_INCLUDE = ../turing-api-c/include
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Include paths
INCLUDES = -I$(INCLUDE_DIR) -I$(INTERNAL_DIR) -I$(C_API_INCLUDE)

# Output library file
LIB_FILE = $(BUILD_DIR)/libturing-api-cpp.a

# Targets
.PHONY: all clean

all: dirs $(LIB_FILE)

dirs:
	mkdir -p $(BUILD_DIR)

# Compile .cpp files to .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create static library
$(LIB_FILE): $(OBJ_FILES)
	llvm-ar rcs $@ $^

clean:
	rm -rf $(BUILD_DIR)