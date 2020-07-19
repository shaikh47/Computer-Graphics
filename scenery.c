#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

#define PI 3.1415

double degToRad(int angle);

void display(void)
{
int x=100,y=100;
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (255/255.0, 0/255.0, 0/255.0);
glBegin(GL_POLYGON);
glVertex2f (300,400);
glVertex2f (300,500);
glVertex2f (500,500);
glVertex2f (500,400);
glEnd();

glColor3f (255/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
        glVertex2f ((50*cos(degToRad(i))+x),(50*sin(degToRad(i))+y));
    }
    glEnd();

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

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


double degToRad(int angle){
    return (double)angle*PI/180.0;
}
