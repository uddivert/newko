cmake_minimum_required(VERSION 3.12)
project(SDL_Project)

# Set C standard to C11
set(CMAKE_C_STANDARD 11)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
set(SOURCE_FILES
        src/init.c
        src/loadmedia.c
        src/sdlfree.c
        src/test.c)

# Header files
set(HEADER_FILES
        include/sdl_resources.h)

# Executable
add_executable(SDL_Project ${SOURCE_FILES} ${HEADER_FILES})

# Include directories
target_include_directories(SDL_Project PRIVATE include)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Link SDL2
target_link_libraries(SDL_Project PRIVATE SDL2)

# Find SDL_image package
find_package(SDL2_image REQUIRED)

# Link SDL_image
target_link_libraries(SDL_Project PRIVATE SDL2_image)

# Copy resources to build directory
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

