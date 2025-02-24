# Define the C compiler
CC = g++

# Define the C compiler flags
CFLAGS = -Wall -Wextra -g

#Define Libs
LIBS = -lSDL2 -lGL -lSDL2_image

# Define the object files
OBJECTS = main.o Vector3.o Transform.o Object.o Sprite.o

# Define the executable
EXECUTABLE = out

BUILD_DIR = build/

SRC_DIR = src/

# Default target
all: $(EXECUTABLE)

# Link the object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile the source files to create the object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Run target
run: $(EXECUTABLE)
	./$(EXECUTABLE)
