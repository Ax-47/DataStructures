# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c2x -I../../singlyLinkedList
TARGET_DIR = execute
TARGET = $(TARGET_DIR)/example
SRC_DIR = ../..
SRC_FILES = example.c $(SRC_DIR)/singlyLinkedList/singlyLinkedList.c
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
