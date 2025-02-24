# Define the C compiler
CC = g++

# Define the C compiler flags
CFLAGS = -Wall -Wextra -g

#Define Libs
LIBS = -lSDL2 -lGL

# Define the object files
OBJECTS = main.o

# Define the executable
EXECUTABLE = out

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
