# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# SDL2 flags
SDL2_FLAGS = `sdl2-config --cflags`
SDL2_LIBS = `sdl2-config --libs` -lSDL2 -lGL -lSDL2_image

# Directory paths
SRC_DIR = src
BUILD_DIR = build
IGNORE_SOURCES = src/main.cpp

# Files
SOURCES = $(shell find $(SRC_DIR) -name "*.cpp")
SOURCES_WITHOUT_MAIN := $(filter-out $(IGNORE_SOURCES), $(SOURCES))
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Target executable
TARGET = $(BUILD_DIR)/myprogram

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(SDL2_FLAGS) $^ -o $@ $(SDL2_LIBS)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SDL2_FLAGS) -c $< -o $@

# Run target
run: $(TARGET)
	./$(TARGET)

# Clean target
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
# Check headers and sources
# Check headers and sources
check:
	@if [ $(words $(SOURCES_WITHOUT_MAIN)) -ne $(words $(HEADERS)) ]; then \
		echo "Warning: number of source files does not match number of header files." \
	; fi
	@for src in $(SOURCES_WITHOUT_MAIN); do \
		if [ ! -f "$$(echo "$$src" | sed "s/\.cpp/.hpp/")" ]; then \
			echo "Error: missing header file for $$src ($$(echo "$$src" | sed "s/\.cpp/.hpp/"))" \
		; fi \
	done



.PHONY: all run clean check
