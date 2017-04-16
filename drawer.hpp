#pragma once //Include this file only once while compiling

class Drawer
{
	public:
	    enum { CELL_WIDTH = 25, CELL_HEIGHT = 25 };
	    void drawMine(int x, int y);
	    void drawFlag(int x, int y);
	    void drawClosedField(int x, int y);
	    void drawOpenedField(int x, int y, int neighbourMinesCount);
	private:
    	void drawOpenedField(int x, int y); //For Blank Fields
};