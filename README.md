# MineSweeper Game 
## Computer Graphics and Visualization Laboratory Project 10CSL67 (2016-2017 batch)

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
    
#### On Arch based systems
    
    pacman -S mesa

### Linking and Compiling the project
Execute the following commands to compile the project  

      mkdir extraFiles
      g++ -Wall -g -std=c++0x -c "main.cpp" -o "extraFiles/main.o"
      g++ -Wall -g -std=c++0x -c "gameMechanics.cpp" -o "extraFiles/gameMechanics.o"
      g++ -Wall -g -std=c++0x -c "drawer.cpp" -o "extraFiles/drawer.o"
      g++ "extraFiles/drawer.o" -lglut -lGL -lpthread "extraFiles/gameMechanics.o" "extraFiles/main.o" -lglut -lGL -lpthread -o "minesweeperExecutable"
 
### Running the game/project
    ./minesweeperExecutable
