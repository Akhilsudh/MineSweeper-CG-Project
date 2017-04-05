#pragma once

class Drawer
{
	public:
	    enum { CELL_WIDTH = 16, CELL_HEIGHT = 16 };
	    void drawMine(int x, int y);
	    void drawFlag(int x, int y);
	    void drawClosedField(int x, int y);
	    void drawOpenedField(int x, int y, int neighbourMinesCount);
	private:
    	void drawOpenedField(int x, int y);
}