
```makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
EXEC = supemon

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Build executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Run the game
run: $(EXEC)
	./$(EXEC)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Phony targets
.PHONY: clean run
