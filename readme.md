# Authors
This project has been created as part of the 42 curriculum by lhao and xuewang.

# Instruction

## Execution :
Execute in linux with:

```
make
./cub3D <map.cub>
```
To clean object files:

```
make clean
```

To remove all generated files:

```
make fclean
```
The .cub scene file must follow this format:

```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm
F 220,100,0
C 225,30,0

1111111
1000N01
1111111
```

Controls
```
Key Action
W            	Move forward
S            	Move backward
A            	Strafe left
D               Strafe right
← →             Rotate camera left / right
ESC             Close window and exit
Red cross (✕)   Close window and exit
```

# Description
cub3D (a 42 school project)is a first-person 3D representation of a maze using raycasting, which should be similar to Wolfenstein 3D project.

The goal is to render a realistic 3D first-person perspective of the inside of a maze, starting from a 2D map file. The rendering engine is built from scratch in C using the Digital Differential Analyzer (DDA) raycasting algorithm and the miniLibX graphics library.

## Features

action supported:
User can move with W/A/S/D and rotate the view with left arrow and right arrow.

## Structure

In this cub3d, the implementation is follw the based on a DDA(Digital differential analyzer)algorithm,

```
init_game
    ↓
read_map_file
    ↓
init_mlx_engine
    ↓
mlx_loop
with player_move and render(DDA raycasting)
for each frame.

```
### Project Structure

inc/
lib/
src/
    init
    player move
    parsing
    render
    exit

# Resources
https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/
https://lodev.org/cgtutor/raycasting.html
https://fabiensanglard.net/Compile_Like_Its_1992/

## AI Usage

AI tools were used in Debugging: drawing part of the error maps.