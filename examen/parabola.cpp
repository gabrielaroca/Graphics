#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>

using namespace std;

void Parabola()
{
 glClearColor(0, 0, 0, 0);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1, 1, 0);
 glPointSize(0.3);
 glBegin(GL_POINTS);
 for (double x = 0; x <= 10; x += 0.01) {
  glVertex2f(x, -(double) sqrt(4*x));
  glVertex2f(x, (double) sqrt(4*x));
 }
 glEnd();
 glFlush();
}
void init()
{
 glOrtho(15, -15, 15, -15, 15, -15);
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitWindowPosition(50, 50);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Parabola");
 init();
 glutDisplayFunc(Parabola);
 glutMainLoop();

 return 0;
}
