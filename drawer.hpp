#pragma once //Include this file only once while compiling

class Drawer
{
	public:
	    enum { CELL_WIDTH = 30, CELL_HEIGHT = 30 };
	    void drawMine(int x, int y);
	    void drawFlag(int x, int y);
	    void drawClosedField(int x, int y);
	    void drawOpenedField(int x, int y, int neighbourMinesCount);
	    void render(int h, int y);
	private:
    	void drawOpenedField(int x, int y); //For Blank Fields
	    void drawStrokeText(char*string, int x, int y, int z, int size, float scaleFactor);
};