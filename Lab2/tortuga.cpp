/*
El siguiente programa  grafica una tortuga usando circulos desde 
la perspectiva de  poligonos a los cualesse les asigna un radio,
número de lados y la posición inicial en X y Y.

Para manipular el programa se hacen de las siguiente teclas:

Rotacion

t -> arriba
g -> abajo
f -> izquierda
h -> derecha

Translacion

w -> adelante
s -> atras
a -> derecha
d -> izquierda



Escalado

m -> mas
n -> menos

Ejecucion
g++ tortuga.cpp -o t -lglut -lGL -lGLU
./t

*/
#include <GL/glut.h>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string.h>
#include <iostream>

using namespace std;

void turtle(int sides,float radio,int x,int y) {

    std::vector<float> point_x;
    std::vector<float> point_y;
    float PI = 3.14159f;
    float step = (2 * PI )/sides;
    
    for (int i =0; i < sides; i++) {
        point_x.push_back(x+radio*cos(2*PI*i/sides));
        point_y.push_back(y+radio*sin(2*PI*i/sides));
    }

    point_x.push_back(point_x[0]);
    point_y.push_back(point_y[0]);

    glBegin(GL_LINES);
    for(int  i= 0; i < point_x.size()-1; ++i) {
        glVertex2f(point_x[i],point_y[i]);
        glVertex2f(point_x[i+1],point_y[i+1]);
    }
    glEnd();
}


void draw();

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display(void) {
    glColor3f(1,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    draw();
    glColor3f(1,1,0) ;
    
    glutSwapBuffers();
}


void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    turtle(30,1,0,0); //cuerpo
    turtle(30,0.5,0,1);
    turtle(30,0.4,1,1); //pata izquierda abajo
    turtle(30,0.4,1,-1);//pata izquierda arriba
    turtle(30,0.4,-1,1);//pata derecha abajo
    turtle(30,0.4,-1,-1);//pata derecha arriba
    glFlush();

    
}


void keyboard(unsigned char key, int x, int y) {

   switch(key) {
    case 'i' :
        cout<<"rotacion arriba"<<endl;
        glRotatef(5.0, 1.0, 0.0, 0.0);
        break;
    case 'j' : 
        cout<<"rotacion izquierda"<<endl;
        glRotatef(-5.0, 0.0, 1.0, 0.0);
        break;
    case 'k' :
        cout<<"rotacion abajo"<<endl;
        glRotatef(-5.0, 1.0, 0.0, 0.0);
        break;
    case 'l' :
        cout<<"rotacion  derecha"<<endl;
        glRotatef(5.0, 0.0, 1.0, 0.0);
        break;     
    
    case 'w' :
        cout<<"traslacion arriba"<<endl;
        glTranslatef(0.0, 0.1 ,0.0);
        break;
    case 'a' : 
        cout<<"traslacion  izquierda"<<endl;
        glTranslatef(-0.1, 0.0 ,0.0);
        break;
    case 's' :
        cout<<"traslacion abajo"<<endl;
        glTranslatef(0.0, -0.1, 0);
        break;
    case 'd' :
        cout<<"traslacion derecha"<<endl;
        glTranslatef(0.1, 0 ,0.0);
        break;
    
    case 'm' :
        glScalef(2,2,2);
        break;

    case 'n' :
        glScalef(0.5,0.5,0.5);
        break;    
    }
    glutPostRedisplay();
}
void init()
{
    glColor3f(1,0.5,1);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(420, 420);
    glutInitWindowPosition(35, 35);
    glutCreateWindow("graficando tortuga");
    init();
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
