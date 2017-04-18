#include "drawer.hpp"
#include "gameMechanics.hpp"
#include <GL/glut.h>

Game game;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    game.draw();
    glutSwapBuffers();
}

void keyPressed (unsigned char key, int x, int y) {  
    if (key == 'q') { 
        // If they ‘q’ key was pressed exit game
        exit(0);
    }  
    else if(key == 'r'){
        // If they ‘r’ key was pressed restart game
        game = Game();
    }
} 

void reshape(int w, int h)
{   
    glutReshapeWindow(Game::WIDTH * Drawer::CELL_WIDTH, Game::HEIGHT * Drawer::CELL_HEIGHT);
}

void mouse(int button, int state, int x, int y) // Mouse functions here..
{
    if (state == GLUT_UP)
    {
        switch (button)
        {
            case GLUT_LEFT_BUTTON:  //Open that tile
                game.open(x / Drawer::CELL_WIDTH, y / Drawer::CELL_HEIGHT);
                break;
            case GLUT_RIGHT_BUTTON: //Place a Flag here
                game.markFlag(x / Drawer::CELL_WIDTH, y / Drawer::CELL_HEIGHT);
                break;
        }
        glutPostRedisplay();
    }   
}

int main(int argc, char **argv)
{   
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Game::WIDTH * Drawer::CELL_WIDTH, Game::HEIGHT * Drawer::CELL_HEIGHT);
    glutInitWindowPosition(100, 120);
    glutCreateWindow("MineSweeper-CG-Project");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Game::WIDTH * Drawer::CELL_WIDTH, Game::HEIGHT * Drawer::CELL_HEIGHT, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutMouseFunc(mouse); //Call the mouse function here
    glutMainLoop();
}