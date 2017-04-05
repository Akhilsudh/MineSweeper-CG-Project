#include <GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    game.draw();
    glutSwapBuffers();
}

void mouse() // Mouse functions here..

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(140, 140);
    glutInitWindowPosition(100, 120);
    glutCreateWindow("MineSweeper");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 140, 140, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse); //Call the mouse function here
    glutMainLoop();
}