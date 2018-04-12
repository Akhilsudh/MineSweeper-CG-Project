# Wrap-Around MineSweeper
[![Library](https://img.shields.io/badge/Library-OpenGL-orange.svg)](https://www.opengl.org/)
[![License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](https://github.com/Akhilsudh/MineSweeper-CG-Project/blob/master/LICENSE)   
> This project demonstrates a simple game of Mine-Sweeper. Minesweeper is a single-player puzzle
video game. The objective of the game is to clear a square board containing hidden "mines" without
detonating any of them, with help from clues about the number of neighboring mines in each field.
The game is played by revealing squares of the grid by clicking each square. If a square containing a
mine is revealed, the player loses the game. If no mine is revealed, a digit is instead displayed in the square,
indicating how many adjacent squares contain mines; if no mines are adjacent, the square becomes blank. The
player uses this information to deduce the contents of other squares, and may either safely reveal each square
or mark the square as containing a mine by placing a flag.

> The game will be played as follows:
>   1. Left Mouse button to select a box/field and reveal its contents.
>   2. Right Mouse button to place a flag on the square or remove an existing flag.
>   3. On left clicking a field that has a mine, the game is “GAME OVER”
   
### Installing Prerequisites (OpenGL in Linux)
#### On debian based systems
You can install the required dependencies using the following commands

    sudo apt-get update
    sudo apt-get install freeglut3
    sudo apt-get install freeglut3-dev
    sudo apt-get install binutils-gold
    sudo apt-get install g++ cmake
    sudo apt-get install libglew-dev
    sudo apt-get install g++
    sudo apt-get install mesa-common-dev
    sudo apt-get install build-essential
    sudo apt-get install libglew1.5-dev libglm-dev
    sudo apt-get install libxmu-dev libxi-dev
    sudo apt-get install sox
    
#### On Arch based systems
    
    pacman -S mesa

### Running the project using the script
Run the game using the provided script build.sh by using the command
    
    ./build.sh

### Linking and Compiling the project(Without the script)
Execute the following commands to compile the project  

      mkdir extraFiles
      g++ -Wall -g -std=c++0x -c "main.cpp" -o "extraFiles/main.o"
      g++ -Wall -g -std=c++0x -c "gameMechanics.cpp" -o "extraFiles/gameMechanics.o"
      g++ -Wall -g -std=c++0x -c "drawer.cpp" -o "extraFiles/drawer.o"
      g++ "extraFiles/drawer.o" -lglut -lGL -lpthread "extraFiles/gameMechanics.o" "extraFiles/main.o" -lglut -lGL -lpthread -o "minesweeperExecutable"
 
### Running the game/project(Without the script)
    ./minesweeperExecutable

## Screenshots
![Welcome](http://i.imgur.com/yytZauD.png)
![GamePlay](http://i.imgur.com/HZLEAg2.png)
![GameWon](http://imgur.com/G3cH09R.png)
![GameOver](http://imgur.com/nkVDa2r.png)
 
