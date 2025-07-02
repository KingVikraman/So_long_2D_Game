# 🎮 so_long Project Guide

Welcome to the **so_long** project! This guide will walk you through the steps to successfully complete the project from scratch. Whether you're just starting or want a clear checklist, this document is for you.

---

## 🧠 Project Overview

You will build a simple 2D game using **MiniLibX**, a lightweight graphics library. The game must read a map from a file and let the player move through it while collecting items and reaching an exit.

---

## ✅ Project Requirements

- Load a `.ber` map file.
- Map must be:
  - Rectangular
  - Surrounded by walls (`1`)
  - Contain:
    - At least 1 player (`P`)
    - At least 1 exit (`E`)
    - At least 1 collectible (`C`)
- Render the map graphically using `.xpm` images.
- Handle player movement with the keyboard.
- Allow exit only when all collectibles are collected.
- Display the move count.

### 🔥 Bonus (optional)
- Enemies with simple movement
- Animated sprites
- Mouse interaction

---

## 🛠 Project Setup

Recommended folder structure:
so_long/
├── Makefile
├── libft/
├── mlx/
├── assets/
│ ├── player.xpm
│ ├── wall.xpm
│ └── ...
├── maps/
│ └── level1.ber
├── src/
│ ├── main.c
│ ├── map_parser.c
│ ├── render.c
│ ├── events.c
│ ├── utils.c
│ └── ...
└── includes/
└── so_long.h

---

## 🧩 Step-by-Step Development

### 1️⃣ Parse and Validate the Map

- Read the `.ber` map file line by line (use `get_next_line`).
- Store the map in a 2D array.
- Validate:
  - Map is rectangular.
  - Surrounded by walls.
  - Contains only valid characters: `P`, `E`, `C`, `1`, `0`.
  - Contains at least one `P`, one `E`, and one `C`.

### 2️⃣ Initialize MiniLibX & Load Images

- Initialize MLX with `mlx_init()`.
- Create window using `mlx_new_window()`.
- Load `.xpm` images using `mlx_xpm_file_to_image()`.
- Draw each map tile with `mlx_put_image_to_window()`.

### 3️⃣ Handle Player Movement

- Use `mlx_hook()` or `mlx_key_hook()` to capture key events.
- Check if the new position is valid (not a wall).
- If it's a collectible, reduce the count.
- If it's an exit and all collectibles are taken, end the game.
- Count and display number of moves.

### 4️⃣ Exit and Free Resources

- Free all malloc’d memory.
- Destroy all MLX images and window using `mlx_destroy_*` functions.
- Print error messages for invalid maps and exit gracefully.


