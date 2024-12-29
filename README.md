# so_long

![](https://miro.medium.com/v2/resize:fit:683/1*4qQUjHGkLcYPW_YkgOdPIw.png)

This is my solution for the **so_long** project, part of the core curriculum at 42 School.

---

## Project Overview

The **so_long** project is a 2D tile-based game developed in C using the MiniLibX graphical library. Players navigate through a map, collecting items, avoiding obstacles, and reaching the exit to win. This project demonstrates core programming skills such as memory management, event handling, and rendering graphics in real-time.

---

## Features

- **Tile-Based Map Rendering**: Displays a dynamic 2D map.
- **Player Movement**: Navigate using arrow keys or WASD.
- **Collectibles**: Gather items to unlock the exit.
- **Collision Detection**: Prevents movement into walls or invalid areas.
- **Custom Maps**: Supports user-generated `.ber` map files.

---

## Requirements

- Tested on:  
    **macOS Catalina (Version 10.15.7)**.
- Dependencies:
    - **OpenGL**
    - **AppKit**

For Linux users:

- [MiniLibX Linux Guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)
- [MiniLibX Linux Repo](https://github.com/42Paris/minilibx-linux) _(not tested with this project)_

---

## How to Run

1. Clone the repository:
    
     `git clone https://github.com/sbourziq1337/So_long.git`
    
2. Navigate to the directory:

     `cd so_long`
3. Compile the project:

     `make`
    
4. Run the game:
    
     `./so_long <map_file.ber>`
    
---

## Known Issues

- Not tested on Linux or Windows.
- Larger maps may cause performance issues.

----------------------------------------------------------
