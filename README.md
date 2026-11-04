# Pac-Man in C

A simplified version of the arcade classic **Pac-Man**, written in C with **raylib**.
Final project of the C module, made by **Karen** and **Etienne**.

## Presentation

[Slides of the presentation (Google Slides)](https://docs.google.com/presentation/d/1-qQucP7IMyMP0mmIJcvDZQKJJCQAoEcB/edit?usp=sharing)

## The game

Guide Pac-Man through the maze and eat all the dots to win.
Each dot is worth **10 points**. If a ghost catches Pac-Man, the game is over.

> Current version: the maze and the ghosts are working; Pac-Man (player module) is not included yet.

| Key | Action |
|---|---|
| Arrow keys | Move Pac-Man |
| `Esc` | Quit |

Pac-Man keeps moving in the chosen direction until he hits a wall.
The ghosts wander through the maze on their own, choosing random directions at walls and crossroads.

## Libraries

| Library | Version | Use |
|---|---|---|
| [raylib](https://www.raylib.com/) | **6.2** (latest stable) | window, keyboard, drawing |
| C standard library | — | memory, random numbers, strings |

raylib is **included in the `raylib/` folder** and **compiled automatically by `make`**: there is nothing to install.
If the folder is missing, `make` downloads raylib 6.2 first.
raylib is distributed under the zlib license (see `raylib/LICENSE`).

## Requirements

Only a C compiler and `make` are needed:

| System | Install once |
|---|---|
| **Windows** | [MSYS2](https://www.msys2.org/), then in the **MSYS2 UCRT64** terminal: `pacman -S mingw-w64-ucrt-x86_64-gcc make git` |
| **macOS** | `xcode-select --install` |
| **Linux** (Debian / Ubuntu) | `sudo apt install build-essential git libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl1-mesa-dev` |

On Windows, run the commands below in the **MSYS2 UCRT64** terminal, not in PowerShell.

## Build and run

From the `Pac-Man` folder:

```bash
make        # compiles raylib (first time only) and the game
./pacman    # runs the game
```

| Command | Effect |
|---|---|
| `make clean` | removes the game's `.o` files |
| `make fclean` | also removes the executable and the compiled raylib |
| `make re` | recompiles everything |

The first `make` takes about a minute because raylib is compiled. The `Makefile` detects the system
(Windows, macOS or Linux) and links the right system libraries.

## Project structure

```
Pac-Man/
├── Makefile
├── README.md
├── include/     # headers: types, map, ghost, player
├── src/         # code: main, map, ghost, player
└── raylib/      # raylib 6.2 source code
```

- **map:** the maze (walls, dots, empty cells) on a 20 × 15 grid
- **ghost:** the ghosts, created with `malloc` and freed with `free`
- **player:** Pac-Man
- **main:** the window, the game loop and all the drawing

## Task split

| Karen | Etienne |
|---|---|
| Project structure and shared types | Pac-Man (`player` module) |
| Map: maze, walls, dots, drawing | Pac-Man controls and display |
| Ghosts: memory, movement, drawing | |
| Makefile with bundled raylib | |
| README | |