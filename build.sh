rm -rf extraFiles;
rm minesweeperExecutable;
mkdir extraFiles;
g++ -Wall -g -std=c++0x -c "main.cpp" -o "extraFiles/main.o";
g++ -Wall -g -std=c++0x -c "gameMechanics.cpp" -o "extraFiles/gameMechanics.o";
g++ -Wall -g -std=c++0x -c "drawer.cpp" -o "extraFiles/drawer.o";
g++ "extraFiles/drawer.o" -lglut -lGL -lpthread "extraFiles/gameMechanics.o" "extraFiles/main.o" -lglut -lGL -lpthread -o "minesweeperExecutable";
./minesweeperExecutable