# Makefile for zombie process program

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -g  # Enables all warnings and debug symbols

# Target executable
TARGET = zombie

# Default target: build the executable
all: $(TARGET)

# Rule to build the target
$(TARGET): zombie.c
	$(CC) $(CFLAGS) -o $(TARGET) zombie.c

# Clean up the compiled files
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
