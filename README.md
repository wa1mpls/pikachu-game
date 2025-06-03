# Pikachu Console Game

This is a simple console-based version of the classic Pikachu matching game, implemented in C++. Players aim to match pairs of identical tiles within a time limit.

## 📁 Project Structure

```
pikachu_project/
│
├── Checklist-MidtermProject.xlsx   # Project planning and checklist
├── report.pdf                      # Project report
└── source/                         # Source code directory
    ├── MAIN.cpp                    # Entry point of the program
    ├── Game.cpp / Game.h           # Game logic and control
    ├── MENU.cpp / Menu.h           # Menu system and navigation
    ├── Check.cpp / Check.h         # Core logic to validate matching tiles
    ├── Leaderboard.cpp / .h / .txt # Score saving and leaderboard
    ├── Library.h                   # Utility functions
    ├── Background1-3.txt           # Background display using ASCII
```

## 🚀 Features

- Console UI with colored tile rendering
- Playable grid of matching tiles
- Menu navigation: Play game, Leaderboard, Exit
- Score tracking and leaderboard
- Time-limited matching system
- Highlighted path validation for matching tiles

## 🔧 How to Compile and Run

Make sure you have a C++ compiler installed (e.g., `g++`).

### On Windows (Using CMD or PowerShell):

```bash
g++ source/*.cpp -o pikachu.exe
.\pikachu.exe
```

### On Linux/macOS:

```bash
g++ source/*.cpp -o pikachu
./pikachu
```

> This project uses `#include <windows.h>` so it might need platform-specific adaptations to run on non-Windows systems.

## 🧠 Gameplay

- Navigate the menu using keyboard keys.
- Match identical tiles that can be connected with **at most three straight lines**.
- Valid matches are checked by the algorithm in `Check.cpp`.
- Scores are recorded and can be viewed via the leaderboard.

## 📌 Contributors

This project was developed as part of a midterm assignment for an introductory programming or game development course.

## 📄 License

This is an academic project. Use for learning purposes only.
