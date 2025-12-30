# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Source files
SRC = src/main.c src/source.c
OBJ = $(SRC:.c=.o)

# Target executable inside build/
TARGET = build/main.exe

# Default rule
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run with sample test cases
run: $(TARGET)
    $(TARGET) < tests/testcases.txt

# Remove build artifacts
clean:
    rm -f $(TARGET) $(OBJ)
