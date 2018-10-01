/*
El siguiente programa  grafica y rastrea los movimientos de una tortuga usando circulos desde 
la perspectiva de  poligonos a los cualesse les asigna un radio,
número de lados y la posición inicial en X y Y .
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
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;


int np = 0;
float px[10000];
float py[10000];
float pz[10000];
GLdouble mModel[16];
void display(void);
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void turtle(int sides,float radio,int x,int y);


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

void addPointToTrace(){
  int i;
  GLdouble m[16];
  glGetDoublev(GL_MODELVIEW_MATRIX, m);

  printf("\nMatrix:\n");
  for(i=0; i<4; i++){
    printf("Row %i: %f \t%f \t%f \t%f \n", i+1, m[i+0], m[i+4], m[i+8], m[i+12]);
  }

  if(np==0){
    px[0] = 0;
    py[0] = 0;
    pz[0] = 0;
    np++;
  }
  px[np] = m[0] *px[0] + m[4] *py[0] + m[8] *pz[0] +m[12];
  py[np] = m[1] *px[0] + m[5] *py[0] + m[9] *pz[0] +m[13];
  pz[np] = m[2] *px[0] + m[6] *py[0] + m[10] *pz[0] +m[14];
  printf("Point %i: %f \t%f \t%f \n",np, px[np], py[np], pz[np]);
  np++;
}

void displayTrace() {
  int i;
  glColor3f(1.0,0.0,0.0) ;
  glBegin(GL_LINE_STRIP);
    for (i = 0; i < np; i++) {
      glVertex3f (px[i],py[i],pz[i]);
    }
  glEnd();
}

void reshape(int width, int height)
{
  glGetDoublev (GL_MODELVIEW_MATRIX, mModel);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//Traslaciones
void keyboard(unsigned char key, int x, int y)
{
  glPushMatrix();
  glLoadIdentity();
  glMultMatrixd(mModel);

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
  glGetDoublev (GL_MODELVIEW_MATRIX, mModel);
  glPopMatrix();
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
