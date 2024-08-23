# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -I../../pair
TARGET_DIR = execute
TARGET = $(TARGET_DIR)/pair_example
SRC_DIR = ../../pair
SRC_FILES = pair_example.c $(SRC_DIR)/pair.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the target
clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
