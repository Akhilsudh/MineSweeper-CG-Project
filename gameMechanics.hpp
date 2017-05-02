#pragma once //Include this file only once while compiling

class Game
{
	public:
	    
	    enum { WIDTH = 30, HEIGHT = 20 };
	    enum State { CLOSED, OPENED, FLAG }; // 3 possible states of any given field
	    bool gameOver;
	    bool gameWonFlag;

	    Game();
	    void draw();
	    void welcomeScreen();
	    void markFlag(int x, int y);
	    void open(int x, int y);
	    bool gridSweeper(int x, int y);
	    bool gameWin();
	
	private:
	    
	    struct Cell //A struct for each Cell of a field
	    {
	        bool hasMine; //Flag for presence of mine in this field
	        State state; //Current state of the field	        
	    };
	    Cell field_[WIDTH][HEIGHT];
};