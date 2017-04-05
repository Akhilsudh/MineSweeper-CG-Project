#include "drawer.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

void Drawer::drawMine(int x, int y) //Draw a Black Pentagon for a mine
{
	drawOpenedField(x, y); //Place a mine on the opened field
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON); 
    for (int i = 0; i < 5; ++i)
    {    
    	glVertex2f(x * CELL_WIDTH + CELL_WIDTH / 2 + 5.0f * cos(2 * 3.1415926 * i / 5), y * CELL_HEIGHT + CELL_HEIGHT / 2 + 5.0f * sin(2 * 3.1415926 * i / 5));
    }
    glEnd();
}

void Drawer::drawFlag(int x, int y)
{}

void Drawer::drawClosedField(int x, int y)
{}

void Drawer::drawOpenedField(int x, int y, int minesAround)
{}

void Drawer::drawOpenedField(int x, int y)
{}