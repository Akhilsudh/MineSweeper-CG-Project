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
{
	//Draw the Flag that must be placed when clicking the right mouse button
	glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH, (y + 1) * CELL_HEIGHT);
    glVertex2f(x * CELL_WIDTH, (y + 1) * CELL_HEIGHT);
    glEnd();
    //Draw the Black flag pole
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x * CELL_WIDTH + CELL_WIDTH / 2, y * CELL_HEIGHT + 3);
    glVertex2f(x * CELL_WIDTH + CELL_WIDTH / 2, (y + 1) * CELL_HEIGHT - 3);
    glEnd();
    //Draw the red triangle of the flag
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x * CELL_WIDTH + CELL_WIDTH / 2, y * CELL_HEIGHT + 3);
    glVertex2f(x * CELL_WIDTH + CELL_WIDTH / 2 - 3, y * CELL_HEIGHT + 3 + 3);
    glVertex2f(x * CELL_WIDTH + CELL_WIDTH / 2, y * CELL_HEIGHT + 3 + 3 + 3);
    glEnd();
}

void Drawer::drawClosedField(int x, int y)
{}

void Drawer::drawOpenedField(int x, int y, int minesAround)
{}

void Drawer::drawOpenedField(int x, int y)
{}