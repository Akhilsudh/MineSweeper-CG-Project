#include "drawer.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <unistd.h>

int boomOrNumberFlag = 1;

void Drawer::drawWelcomeScreen(int h, int w) //Draws Welcome Screen
{   renderBox(h, w, 3);
    glColor3f(0,0,0);
    glLineWidth(5.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawStrokeText("MineSweeper", (w/3)*CELL_WIDTH + 15, (h/3)*CELL_HEIGHT + 65, 0, 0.5, 0.35f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawStrokeText("By", (w/3)*CELL_WIDTH + 15, (h/3)*CELL_HEIGHT + 105, 0, 1.0, 0.25f);
    drawStrokeText("Akhil S", (w/3)*CELL_WIDTH + 15, (h/3)*CELL_HEIGHT + 145, 0, 0.8, 0.25f);
    drawStrokeText("Abhijith C", (w/3)*CELL_WIDTH + 15, (h/3)*CELL_HEIGHT + 185, 0, 0.8, 0.25f);
    glLineWidth(1.0);
    glutSwapBuffers(); 
}

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

void Drawer::drawStrokeText(const char*string, int x, int y, int z, int size, float scaleFactor)
{
      const char *c;
      glPushMatrix();
      glTranslatef(x, y,z);
      glScalef(scaleFactor,-scaleFactor,z);
      
  
      for (c=string; *c != '\0'; c++)
      {
            glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
            glutStrokeWidth(GLUT_STROKE_ROMAN, size);
      }
      glPopMatrix();
}

void Drawer::renderBox(int h, int w, int scale)
{ 
    //Create a Closed Grey Box 
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f((w/scale)*CELL_WIDTH, (h/scale)*CELL_HEIGHT);
    glVertex2f((2*w/scale)*CELL_WIDTH, (h/scale)*CELL_HEIGHT);
    glVertex2f((2*w/scale)*CELL_WIDTH, (2*h/scale)*CELL_HEIGHT);
    glVertex2f((w/scale)*CELL_WIDTH, (2*h/scale)*CELL_HEIGHT);
    glEnd();
    //Lines for tile effect
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f((w/scale)*CELL_WIDTH, (h/scale)*CELL_HEIGHT);
    glVertex2f((2*w/scale)*CELL_WIDTH - 1, (h/scale)*CELL_HEIGHT);
    glVertex2f((w/scale)*CELL_WIDTH, (h/scale)*CELL_HEIGHT);
    glVertex2f((w/scale)*CELL_WIDTH, (2*h/scale)*CELL_HEIGHT - 1);
    glEnd();
    //Dark grey Lines for depth
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f((2*w/scale)*CELL_WIDTH - 1, (h/scale)*CELL_HEIGHT);
    glVertex2f((2*w/scale)*CELL_WIDTH - 1, (2*h/scale)*CELL_HEIGHT - 1);
    glVertex2f((w/scale)*CELL_WIDTH, (2*h/scale)*CELL_HEIGHT - 1);
    glVertex2f((2*w/scale)*CELL_WIDTH - 1, (2*h/scale)*CELL_HEIGHT - 1);
    glEnd();
    
}

void Drawer::gameOver(int h, int w)
{
    renderBox(h, w, 3);
    //Draw Game Over text on the box generated above
    glColor3f(0,0,0);
    glLineWidth(5.0);
    drawStrokeText("GAME OVER", (w/3)*CELL_WIDTH+5, (h/3)*CELL_HEIGHT + 60, 0, 0.5, 0.35f);
    glLineWidth(1.0);
    glLineWidth(3.0);
    drawStrokeText("Press R to restart", (w/3)*CELL_WIDTH + 5, (h/3)*CELL_HEIGHT + 100, 0, 0.2, 0.15f);
    drawStrokeText("Press Q to quit", (w/3)*CELL_WIDTH + 5, (h/3)*CELL_HEIGHT + 150, 0, 0.2, 0.15f);
    glLineWidth(1.0);
    glutSwapBuffers(); 
}
///////////////////////////////////////////////////////
void Drawer::gameWon(int h, int w)
{
    renderBox(h, w, 3);
    //Draw Game Over text on the box generated above
    glColor3f(0,0,0);
    glLineWidth(5.0);
    drawStrokeText("GAME WON", (w/3)*CELL_WIDTH+5, (h/3)*CELL_HEIGHT + 60, 0, 0.5, 0.35f);
    glLineWidth(1.0);
    glLineWidth(3.0);
    drawStrokeText("Press R to restart", (w/3)*CELL_WIDTH + 5, (h/3)*CELL_HEIGHT + 100, 0, 0.2, 0.15f);
    drawStrokeText("Press Q to quit", (w/3)*CELL_WIDTH + 5, (h/3)*CELL_HEIGHT + 150, 0, 0.2, 0.15f);
    glLineWidth(1.0);
    glutSwapBuffers(); 
}