//Ejercicio 2.4.1//
#include <GL/glut.h>
#include <math.h>

#include <iostream>

#define M_PI 3.14159265358979323846
using namespace std;

int num_lados;
double radio;
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
	glColor3f(1,0.5,1);
	glLoadIdentity();
	GLfloat grados_1;
	GLfloat grados_2;
	glBegin(GL_LINES);	
    //double radio = 0.2;
	double puntos = 360.0f/num_lados;
	
    for(double i=0;i<360;i=i+puntos){
		grados_1 = (GLfloat)i*M_PI/180.0f;
		grados_2 = ((GLfloat)i+puntos)*M_PI/180.0f;
		glVertex3f(radio*cos(grados_1),radio*sin(grados_1),0.0f);
		glVertex3f(radio*cos(grados_2),radio*sin(grados_2),0.0f);
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
	cout<<"Ingrese el numero de lados"<<endl;
	cin>>num_lados;
    cout<<"Ingrese radio:"<<endl;
	cin>>radio;
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Poligono_circunferencia");
	init();
	glutDisplayFunc(display);	
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
/*Ejecutar
g++ grafica.cpp -o ejercicio -lglut -lGL -lGLU
./ejercicio
*/
