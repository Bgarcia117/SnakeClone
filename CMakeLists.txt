cmake_minimum_required(VERSION 3.28)
project(SnakeClone LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Pull SFML 3.0.1 directly from GitHub
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Define your executable
add_executable(SnakeClone
    src/main.cpp
    src/game.cpp
    src/snake.cpp
 "include/food.h" "src/food.cpp")

# Include headers
target_include_directories(SnakeClone PRIVATE include)

# Use C++17
target_compile_features(SnakeClone PRIVATE cxx_std_17)

# Link against SFML 3.0.1
target_link_libraries(SnakeClone PRIVATE SFML::Graphics)
