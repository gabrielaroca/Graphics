#include <GL/glut.h>
#include <iostream>

double x1,x2,y1,y2;

using namespace std;


void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0.5,0);
	glLoadIdentity();
	double m=(y2-y1)/(x2-x1);
	glBegin(GL_POINTS);
	double x,y;
	for (x=x1; x<x2; x+=0.000001)
	{
		y=(y1+m*(x-x1));
		glVertex3f(x,y,0.0f);
	}
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	cout<<"Ingrese las coordenadas"<<endl;
	cout<<"x1:"<<endl;
	cin>>x1;
	cout<<"y1:"<<endl;
	cin>>y1;
	cout<<"x2:"<<endl;
	cin>>x2;
	cout<<"y2:"<<endl;
	cin>>y2;
	x1/=100; x2/=100; y1/=100; y2/=100;
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Línea algoritmo básico");
	init();
	glutDisplayFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
/*Ejecutar
g++ linea1_opengl.cpp -o linea1 -lglut -lGL -lGLU
./linea1
*/
