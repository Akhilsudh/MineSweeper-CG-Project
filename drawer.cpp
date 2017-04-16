#include "drawer.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <unistd.h>

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
{
	//Create a Closed Grey Box 
	glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH, (y + 1) * CELL_HEIGHT);
    glVertex2f(x * CELL_WIDTH, (y + 1) * CELL_HEIGHT);
    glEnd();
    //Lines for tile effect
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(x * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH - 1, y * CELL_HEIGHT);
    glVertex2f(x * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f(x * CELL_WIDTH, (y + 1) * CELL_HEIGHT - 1);
    glEnd();
    //Dark grey Lines for depth
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f((x + 1) * CELL_WIDTH - 1, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH - 1, (y + 1) * CELL_HEIGHT - 1);
    glVertex2f(x * CELL_WIDTH, (y + 1) * CELL_HEIGHT - 1);
    glVertex2f((x + 1) * CELL_WIDTH - 1, (y + 1) * CELL_HEIGHT - 1);
    glEnd();
}

void Drawer::drawOpenedField(int x, int y, int neighbourMinesCount)
{
	drawOpenedField(x, y);
    if (neighbourMinesCount > 0)
    {
        switch (neighbourMinesCount)
        {
	        case 1:
	            glColor3f(0.0f, 1.0f, 0.0f); //Green
	            break;
	        case 2:
	            glColor3f(0.0f, 0.0f, 1.0f); //Blue
	            break;
	        case 3:
	            glColor3f(1.0f, 0.0f, 0.0f); //Red 
	            break;
	        case 4:
	            glColor3f(0.0f, 0.7f, 0.0f); //Celebi Green
	            break;
	        case 5:
	            glColor3f(0.5f, 0.4f, 0.0f); //Dragonite Orange
	            break;
	        case 6:
	            glColor3f(0.0f, 0.8f, 0.5f); //Grovyle Green
	            break;
	        case 7:
	            glColor3f(0.1f, 0.1f, 0.1f); //Onyx Grey
	            break;
	        case 8:
	            glColor3f(0.3f, 0.3f, 0.3f); //Geodude Grey
	            break;
        }
        glRasterPos2f(x * CELL_WIDTH + (15 - 9) / 2 + 1, (y + 1) * CELL_HEIGHT - 1); //Position the number in the center of the block
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0' + neighbourMinesCount); //Create a BitMap Character of the number of neighbouring mines
    }
}

void Drawer::drawOpenedField(int x, int y)
{
	//This overloaded function just draws a plain Opened Block with no Neighbouring Mines count
	
	//Light Grey Box
	glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(x * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH, (y + 1) * CELL_HEIGHT);
    glVertex2f(x * CELL_WIDTH, (y + 1) * CELL_HEIGHT);
    glEnd();
    //Dark Grey Borders for Depth
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f((x + 1) * CELL_WIDTH - 1, y * CELL_HEIGHT);
    glVertex2f((x + 1) * CELL_WIDTH - 1, (y + 1) * CELL_HEIGHT - 1);
    glVertex2f(x * CELL_WIDTH, (y + 1) * CELL_HEIGHT - 1);
    glVertex2f((x + 1) * CELL_WIDTH - 1, (y + 1) * CELL_HEIGHT - 1);
    glEnd();
}