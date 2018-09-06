#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

int num_lados;
int x, y;

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
    GLfloat angulo;
    GLfloat angulo1;
    glBegin(GL_LINES);  
    double i;
    double puntos = 360.0f/num_lados;
    for(i=0;i<360;i=i+puntos)
    {
        angulo = (GLfloat)i*3.14159f/180.0f; 
        angulo1 = ((GLfloat)i+puntos)*3.14159f/180.0f;
        glVertex3f(cos(angulo),sin(angulo),0.0f);
        glVertex3f(cos(angulo1),sin(angulo1),0.0f);

    }

    double radio=1.0;
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    GLfloat twicePi = 2.0f*3.14159;
    for(i=0;i<360;i=i+0.001){
        glVertex2f(
            x+(radio*cos(i*twicePi)),
            y+(radio*sin(i*twicePi))
        );
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
    cout<<"Ingrese el número de lados"<<endl;
    cin>>num_lados;
    glutInitWindowPosition(50, 50); 
    glutInitWindowSize(400, 400); 
    glutCreateWindow("Poligono");
    init();
    glutDisplayFunc(display);   
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}   
/*Ejecutar
g++ poligono.cpp -o poligono -lglut -lGL -lGLU
./poligono
*/
