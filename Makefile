CC = gcc
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := include

SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

# DEPFLAGS specifies options for dependency generation
# -MMD generates dependency information in Makefile-compatible format
# -MP generates empty rules for each header file to avoid Makefile errors
DEPFLAGS = -MMD -MP

# COMPILER_FLAGS specifies additional compilation options
# -w suppresses all warnings; consider removing for more informative build output
COMPILER_FLAGS = -Wall -Wextra

# LINKER_FLAGS specifies the libraries to link against
# -lSDL2 links against the SDL2 library
# -lSDL_image links against the SDL_image library
LINKER_FLAGS = -lSDL2 -lSDL_image

OBJ_NAME = Render

.PHONY: all clean

# Default target, builds the main executable
all: $(OBJ_DIR) $(OBJ_NAME)

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linking step to create the executable
$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# Compilation rule for source files to object files with dependency generation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -I$(INCLUDE_DIR) $(DEPFLAGS) $(COMPILER_FLAGS) $< -o $@

# Include generated dependency files
-include $(OBJS:.o=.d)

# Runs the program
run:
	./$(OBJ_NAME)
# Target to clean up generated files
clean:
	rm -rf $(OBJ_DIR) $(OBJ_NAME) *.d
