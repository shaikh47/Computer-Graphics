#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

#define PI 3.1415

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void grass(int x,int y,float z);
double mapValueY(int value);
double mapValueX(int value);
double mapValueZ(int value);
void house(void);
void land(void);
void tree(void);
void mountain(void);
void grass(int x,int y);
void bird(int point);
void nouka(void);
void circle(float x,float y,float z,int radius);
double degToRad(int angle);
void treeD(float x,float y, int factor);




float _angle = 45.0f;
float angle2 = 0.0f;

using namespace std;
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':  //left
        _angle += 1.0f;
        break;
    case 'd':  //right
        _angle -= 1.0f;
        break;
    case 'w':  //right
        angle2 += 1.0f;
        break;
    case 's':  //right
        angle2 -= 1.0f;
        break;
    }
}
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH); //Enable smooth shading
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double) w / (double) h, 1.0, 200.0);
}

float _cameraAngle = 0.0f;
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-angle2, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    glColor3f(1.0, 0.25, 1.0);
    glColor3f (.5, 0.5, .25);


    /* window 1 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25,-0.01);
    glVertex3f (0.83, 0.25,-0.01);
    glVertex3f (0.83, 0.4,-0.01);
    glVertex3f (0.72, 0.4,-0.01);
    glEnd();

    /* window 2 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25, -0.01);
    glVertex3f (0.38, 0.25, -0.01);
    glVertex3f (0.38, 0.4, -0.01);
    glVertex3f (0.27, 0.4, -0.01);
    glEnd();



    /* main rec */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (153/255.0, 99/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*back rec*/
    glColor3f (184/255.0, 123/255.0, 9/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* left rec */
    glColor3f (130/255.0, 86/255.0, 5/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* right rec */
    glColor3f (189/255.0, 125/255.0, 8/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glEnd();

    /* left tri */
    glColor3f (77/255.0, 72/255.0, 63/255.0);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    /* right tri */
    glColor3f (77/255.0, 72/255.0, 63/255.0);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* roof */
    glColor3f (117/255.0, 109/255.0, 95/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.505, -0.08);
    glVertex3f (0.9, 0.505, -0.08);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*back roof */
    glColor3f (117/255.0, 109/255.0, 95/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.505, 0.58);
    glVertex3f (0.9, 0.505, 0.58);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /* door */
    glColor3f (71/255.0, 52/255.0, 16/255.0);
    glBegin(GL_QUADS);
    glVertex3f (0.47, 0.105, -0.01);
    glVertex3f (0.65, 0.105, -0.01);
    glVertex3f (0.65, 0.46, -0.01);
    glVertex3f (0.47, 0.46, -0.01);
    glEnd();

    circle(200.0,1100,0,150);
    treeD(0,0.25,10);
    treeD(0,0.45,40);
    treeD(0,0.65,80);

    //floor
    glColor3f (128/255.0, 104/255.0, 52/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-5, 0.1, -5);
    glVertex3f (-5, 0.1, 5);
    glVertex3f (5, 0.1, 5);
    glVertex3f (5, 0.1, -5);
    glEnd();

    //paddy field
    glColor3f (52/255.0, 128/255.0, 55/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-1, 0.105, -0.5+0.5);
    glVertex3f (-1, 0.105, 0.1+0.5);
    glVertex3f (-0.55, 0.105, 0.1+0.5);
    glVertex3f (-0.55, 0.105, -0.5+0.5);
    glEnd();

    int x=0;
    float z=0;
    for(int i=50;i<300;i+=50){
        for(int y=0;y<150;y+=45){
        grass(y-450,50,z);
        grass(y-450,50,z);
        grass(y-450,50,z);
        grass(y-450,50,z);
    }
    x+=60;
    z+=0.1;
}

    glPopMatrix();
    glutSwapBuffers();
    glFlush ();
}
void update(int value) {
    //_angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    if (angle2 > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("3D House Rotate");
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}



void treeD(float x,float y,int factor){
    glColor3f (21/255.0, (71+factor)/255.0, 16/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.5+x, 0+y, 0.0);
    glVertex3f (-0.1+x, 0+y, 0.0);
    glVertex3f (-0.3+x, 0.4+y, 0.2);
    glEnd();

    glColor3f (22/255.0, (92+factor)/255.0, 15/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.5+x, 0+y, 0.4);
    glVertex3f (-0.1+x, 0+y, 0.4);
    glVertex3f (-0.3+x, 0.4+y, 0.2);
    glEnd();

    glColor3f (19/255.0, (102+factor)/255.0, 10/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.5+x, 0+y, 0.4);
    glVertex3f (-0.5+x, 0+y, 0.0);
    glVertex3f (-0.3+x, 0.4+y, 0.2);
    glEnd();

    glColor3f (19/255.0, (122+factor)/255.0, 27/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.1+x, 0+y, 0.4);
    glVertex3f (-0.1+x, 0+y, 0.0);
    glVertex3f (-0.3+x, 0.4+y, 0.2);
    glEnd();
    //tree stem
    glColor3f (99/255.0, (68)/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.35, 0.3, 0.2-0.05);
    glVertex3f (-0.35, 0.1, 0.2-0.05);
    glVertex3f (-0.25, 0.1, 0.2-0.05);
    glVertex3f (-0.25,0.3, 0.2-0.05);
    glEnd();

    glColor3f (79/255.0, (55)/255.0, 2/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.25, 0.3, 0.3-0.05);
    glVertex3f (-0.25, 0.1, 0.3-0.05);
    glVertex3f (-0.25, 0.1, 0.2-0.05);
    glVertex3f (-0.25,0.3, 0.2-0.05);
    glEnd();

    glColor3f (69/255.0, (48)/255.0, 3/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.35, 0.3, 0.3-0.05);
    glVertex3f (-0.35, 0.1, 0.3-0.05);
    glVertex3f (-0.35, 0.1, 0.2-0.05);
    glVertex3f (-0.35,0.3, 0.2-0.05);
    glEnd();

    glColor3f (148/255.0, (102)/255.0, 4/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.35, 0.3, 0.3-0.05);
    glVertex3f (-0.35, 0.1, 0.3-0.05);
    glVertex3f (-0.25, 0.1, 0.3-0.05);
    glVertex3f (-0.25,0.3, 0.3-0.05);
    glEnd();
}

void circle(float x,float y,float z,int radius){
    glColor3f (250/255.0, 250/255.0, 0/255.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
        glVertex3f (mapValueZ(radius*cos(degToRad(i))+x),mapValueZ(radius*sin(degToRad(i))+y),z);
    }
    glEnd();
}

void grass(int x,int y,float z){
    glColor3f (4/255.0, 115/255.0, 2/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(x),mapValueY(y),z);
    glVertex3f (mapValueX(x-5-15),mapValueY(y+25),z);
    glVertex3f (mapValueX(x-15),mapValueY(y+30),z);
    glVertex3f (mapValueX(x+5-15),mapValueY(y+25),z);
    glVertex3f (mapValueX(x),mapValueY(y),z);
    glEnd();

    glColor3f (7/255.0, 145/255.0, 4/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(x),mapValueY(y),z);
    glVertex3f (mapValueX(x-5),mapValueY(y+25),z);
    glVertex3f (mapValueX(x),mapValueY(y+30),z);
    glVertex3f (mapValueX(x+5),mapValueY(y+25),z);
    glVertex3f (mapValueX(x),mapValueY(y),z);
    glEnd();

    glColor3f (11/255.0, 232/255.0, 7/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(x),mapValueY(y),z);
    glVertex3f (mapValueX(x-5+15),mapValueY(y+25),z);
    glVertex3f (mapValueX(x+15),mapValueY(y+30),z);
    glVertex3f (mapValueX(x+5+15),mapValueY(y+25),z);
    glVertex3f (mapValueX(x),mapValueY(y),z);
    glEnd();
}


double mapValueX(int value) {
    return ((double)value) / (500.000);
}

double mapValueY(int value) {
    return ((double)value) / (500.000);
}

double mapValueZ(int value) {
    return ((double)value) / (1000.000);
}

double degToRad(int angle){
    return (double)angle*PI/180.0;
}

