
# ABOUT

The "so_long" project is a part of 42's curriculum and involves creating a 2D game using C programming language and the MinilibX graphic library. The game requires players to navigate through a maze, collecting items and avoiding obstacles.

The project includes learning about file descriptors (fd) and their use in reading from a map file as well as how to deal with structs. These are important concepts in C programming, and this project provides an opportunity to practice both in a fun and engaging way.

#### Do you want to know more about it? 
[Click here](https://github.com/ziliolu/42_so_long/blob/main/so_long_subject.pdf) to access the complete subject of this project.
## ⚙️ HOW TO INSTALL & PLAY 

#### 1º - Clone the repository

```bash
  git clone git@github.com:ziliolu/42_so_long.git
```

#### 2º - Enter the project folder and run `make`

```bash
    cd so_long && make 
```

#### 3º - Choose a map from `maps` folder or test with your own map 

```bash
    ./so_long maps/valid1
```
```bash
    ./so_long path_to_your_own_map
```

## 🎮 GAME RULES

- The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
- At every move, the current number of movements must be displayed in the shell (or on the screen, for bonus!).
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- You have to use a 2D view (top-down or profile)


## 🚨 DISCLAIMER 

Maybe you could notice a different coding style.
At 42 we need to follow some rules according to the coding standard of the school such as:

```bash
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
[Click here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf) to read the norm file of 42 school. 


##  ✅ TESTERS

- [Map Validator](https://github.com/Nuno-Jesus/so_long_map_validator)
