# SnakeClone

# 🐍 Snake Game – SFML Clone

This is a simple clone of the classic **Snake** game, built using **C++** and **SFML**. 

---

## 📌 About the Project

The objective of this project is to:

- Learn and apply SFML for game development.
- Practice core programming concepts like object-oriented design, event handling, and rendering.
- Build a working game from scratch and develop a clean project structure.

---

## 🎮 Features (In Progress)

- Smooth Snake movement using arrow keys
- Randomly spawning food (apple)
- Snake grows when food is eaten
- Game over when snake hits itself or the wall
- Basic scoring system
- Organized and readable codebase

---

## 🗂️ Project Structure

snake_game/
├── include/              # Header files (interfaces)
│   ├── game.h
│   └── snake.h
│
├── src/                  # Source files (implementation)
│   ├── game.cpp
│   ├── snake.cpp
│   └── main.cpp
│
├── assets/               # (Optional) Sprites, fonts, or audio
├── CMakeLists.txt        # (Optional) CMake build configuration
└── README.md             # Project information


---

## ⚙️ How to Build and Run

### Requirements
- C++17 or later
- SFML 3.0 or later
- CMake

# Open PowerShell or Command Prompt

# Navigate to your project directory
cd SnakeClone

# Create and enter the build directory
mkdir build
cd build

# Generate Visual Studio project files
cmake .. -G "Visual Studio 17 2022" -A x64

# Build the project in Release mode
cmake --build . --config Release

