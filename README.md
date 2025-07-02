# So_long_2D_Game
I am building a mini 2D game using MinilibX (the graphical lib from 42). The game reads a map file, displays the map using images (walls, floors, player, exits, etc.), and lets the player move around using the keyboard.

🏁 STEP 1: Understand the Requirements 📜
Must-have features:
  • Read a .ber map file
  • Map must be rectangular, closed (surrounded by walls), and have:
      • At least 1 player (P)
      • At least 1 exit (E)
      • At least 1 collectible (C)
  • Show the map using images
  • Allow player to move using arrow/WASD keys
  • Exit only when all collectibles are collected
  • Count and display number of moves

🔗 Bonus (if you're doing bonus part):
  • Enemies that move
  • Animation
  • Mouse support

🛠 STEP 2: Setup Your Project 🔧

so_long/
├── Makefile
├── libft/
├── mlx/
├── assets/
│   ├── player.xpm
│   ├── wall.xpm
│   └── ...
├── maps/
│   └── level1.ber
├── src/
│   ├── main.c
│   ├── map_parser.c
│   ├── render.c
│   ├── events.c
│   ├── utils.c
│   └── ...
└── includes/
    └── so_long.h

🗺 STEP 3: Parse and Validate the Map 🧩

You’ll write code to:
   • Read the file (line by line, use get_next_line)
   • Store it in a 2D array
   • Check:
     • All lines are same length
     • Surrounded by walls
     • Has only allowed characters: P, E, C, 1, 0
     • Has at least 1 of each required (P, E, C)

🔍 Tips:
   • Create a t_game struct to hold map, player pos, collectibles count, etc.


