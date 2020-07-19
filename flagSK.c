#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

#define PI 3.1415

double mapValueY(int value);
double mapValueX(int value);
void circle(int angle,int x,int y,int radius,int r,int g,int b);
double degToRad(int angle);

void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/


glColor3f (255/255.0, 255/255.0, 255/255.0);
glBegin(GL_POLYGON);
glVertex2f(250,500);
glVertex2f(250,300);
glVertex2f(550,300);
glVertex2f(550,500);
glEnd();

glLineWidth(7);
glColor3f (0/255.0, 0/255.0, 0/255.0);
glBegin(GL_LINES);
glVertex2f(300,440);
glVertex2f(330,480);

glVertex2f(310,440-10);
glVertex2f(340,480-10);

glVertex2f(320,440-20);
glVertex2f(350,480-20);
glEnd();

glColor3f (0/255.0, 0/255.0, 0/255.0);
glBegin(GL_LINES);
glVertex2f(330,440-120);
glVertex2f(300,480-120);

glVertex2f(322,460+14-120);
glVertex2f(310,480+10-120);

glVertex2f(341,460+10-140);
glVertex2f(329,480+10-145);

glVertex2f(350,440+20-120);
glVertex2f(320,480+20-120);
glEnd();


glColor3f (0/255.0, 0/255.0, 0/255.0);
glBegin(GL_LINES);
glVertex2f(440,332);
glVertex2f(452,346);

glVertex2f(457,354);
glVertex2f(470,370);
//
glVertex2f(440+12,332-5);
glVertex2f(452+12,346-5);

glVertex2f(457+12,354-5);
glVertex2f(470+12,370-5);
//
glVertex2f(440+24,332-10);
glVertex2f(452+24,346-10);
glVertex2f(440+5,455+2);
glVertex2f(455+4,440+2);
glVertex2f(457+24,354-10);
glVertex2f(470+24,370-10);

glEnd();

glColor3f (0/255.0, 0/255.0, 0/255.0);
glBegin(GL_LINES);
glVertex2f(445,457);
glVertex2f(459,442);
glVertex2f(463,435);
glVertex2f(474,422);

glVertex2f(445+20,457+18);
glVertex2f(459+20,442+18);
glVertex2f(463+20,435+18);
glVertex2f(474+20,422+18);

glVertex2f(445+10,457+10);
glVertex2f(474+10,422+10);
glEnd();


circle(360,400,400,50,3,3,128);
circle(180,400,400,50,255,0,0);
circle(360,375,400,25,255,0,0);
circle(360,425,400,25,3,3,128);
/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0/255.0, 0/255.0, 0/255.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1000.0, 0.0, 600.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
double mapValueX(int value) {
    return ((double)value) / (1000.000);
}

double mapValueY(int value) {
    return ((double)value) / (600.000);
}

int main(int argc, char** argv)
{
    printf("%lf",mapValueX(420));
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}



void circle(int angle,int x,int y,int radius,int r,int g,int b){
    glColor3f (r/255.0, g/255.0, b/255.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=angle;i++){
        glVertex2f ((radius*cos(degToRad(i))+x),(radius*sin(degToRad(i))+y));
    }
    glEnd();
}

double degToRad(int angle){
    return (double)angle*PI/180.0;
}
