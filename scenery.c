#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<math.h>

#define PI 3.1415

double mapValueY(int value);
double mapValueX(int value);
void house(void);
void land(void);
void tree(void);
void mountain(void);
void grass(int x,int y);
void bird(int point);
void nouka(void);
void circle(int x,int y,int radius);
double degToRad(int angle);

void display(void)
{
/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
mountain();
land();
tree();
house();
nouka();
int x=0;
for(int i=50;i<200;i+=50){
    for(int y=0;y<300-x;y+=45){
        grass(y,i);
        grass(y,i);
        grass(y,i);
        grass(y,i);
    }
    x+=45;
}
circle(900,500,50);
/* don't wait!
* start processing buffered OpenGL routines
*/
glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (7/255.0, 201/255.0, 227/255.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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

void house(void){
    glLineWidth(1);
    glColor3f (87/255.0, 57/255.0, 28/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(400), mapValueY(620-200), 0.0);  //a
    glVertex3f (mapValueX(600), mapValueY(620-200), 0.0);
    glVertex3f (mapValueX(650), mapValueY(470-200), 0.0);
    glVertex3f (mapValueX(450), mapValueY(470-200), 0.0);
    glEnd();

    glColor3f (61/255.0, 41/255.0, 21/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(360), mapValueY(470-200), 0.0);  //b
    glVertex3f (mapValueX(380), mapValueY(470-200), 0.0);
    glVertex3f (mapValueX(410), mapValueY(590-200), 0.0);
    glVertex3f (mapValueX(400), mapValueY(620-200), 0.0);
    glEnd();

    glColor3f (138/255.0, 82/255.0, 26/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(410), mapValueY(590-200), 0.0);  //d
    glVertex3f (mapValueX(450), mapValueY(470-200), 0.0);
    glVertex3f (mapValueX(450), mapValueY(390-200), 0.0);
    glVertex3f (mapValueX(380), mapValueY(400-200), 0.0);
    glVertex3f (mapValueX(380), mapValueY(470-200), 0.0);
    glEnd();



    glColor3f (138/255.0, 78/255.0, 29/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(450), mapValueY(470-200), 0.0);  //e
    glVertex3f (mapValueX(630), mapValueY(470-200), 0.0);
    glVertex3f (mapValueX(630), mapValueY(400-200), 0.0);
    glVertex3f (mapValueX(450), mapValueY(390-200), 0.0);
    glEnd();


    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(400), mapValueY(470-200), 0.0);  //c
    glVertex3f (mapValueX(425), mapValueY(473-200), 0.0);
    glVertex3f (mapValueX(425), mapValueY(396-200), 0.0);
    glVertex3f (mapValueX(400), mapValueY(400-200), 0.0);
    glEnd();

    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(520), mapValueY(461-200), 0.0);  //f
    glVertex3f (mapValueX(555), mapValueY(460-200), 0.0);
    glVertex3f (mapValueX(555), mapValueY(399-200), 0.0);
    glVertex3f (mapValueX(520), mapValueY(397-200), 0.0);
    glEnd();

    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(470), mapValueY(461-200), 0.0);  //h
    glVertex3f (mapValueX(500), mapValueY(460-200), 0.0);
    glVertex3f (mapValueX(500), mapValueY(430-200), 0.0);
    glVertex3f (mapValueX(470), mapValueY(429-200), 0.0);
    glEnd();

    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(470+110), mapValueY(461-202), 0.0);  //g
    glVertex3f (mapValueX(500+110), mapValueY(460-202), 0.0);
    glVertex3f (mapValueX(500+110), mapValueY(430-198), 0.0);
    glVertex3f (mapValueX(470+110), mapValueY(429-198), 0.0);
    glEnd();


    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_LINES);
    glVertex3f (mapValueX(450), mapValueY(390-200), 0.0);  //line
    glVertex3f (mapValueX(450), mapValueY(470-200), 0.0);
    glEnd();
    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_LINES);
    glVertex3f (mapValueX(630), mapValueY(400-200), 0.0);  //line
    glVertex3f (mapValueX(450), mapValueY(390-200), 0.0);
    glEnd();

    glLineWidth(5);
    glColor3f (79/255.0, 40/255.0, 1/255.0);  //fence
    glBegin(GL_LINES);
    glVertex2f (mapValueX(650), mapValueY(260));
    glVertex2f (mapValueX(750), mapValueY(275));
    glEnd();

    glBegin(GL_LINES);
    glVertex2f (mapValueX(650), mapValueY(220));
    glVertex2f (mapValueX(750), mapValueY(235));
    glEnd();

    for(int i=0;i<5;i++){
        glBegin(GL_LINES);
        glVertex2f (mapValueX(660+(i*20)), mapValueY(210+i*2.5));
        glVertex2f (mapValueX(660+(i*20)), mapValueY(280+i*2.5));
        glEnd();
    }
}


void land(void){
    glColor3f (88/255.0, 161/255.0, 38/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(0), mapValueY(460-150), 0.0);  //a
    glVertex3f (mapValueX(1000), mapValueY(460-150), 0.0);
    glVertex3f (mapValueX(1000), mapValueY(360-100), 0.0);

    glVertex3f (mapValueX(850), mapValueY(325-100), 0.0);
    glVertex3f (mapValueX(950), mapValueY(275-100), 0.0);

    glVertex3f (mapValueX(700), mapValueY(230-100), 0.0);
    glVertex3f (mapValueX(800), mapValueY(180-100), 0.0);

    glVertex3f (mapValueX(0), mapValueY(110-100), 0.0);
    glEnd();
}

void tree(void){
    glColor3f (107/255.0, 66/255.0, 41/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(200), mapValueY(200+30), 0.0);  //a
    glVertex3f (mapValueX(250), mapValueY(200+30), 0.0);
    glVertex3f (mapValueX(250), mapValueY(300+30), 0.0);
    glVertex3f (mapValueX(200), mapValueY(300+30), 0.0);
    glEnd();

    glColor3f (37/255.0, 84/255.0, 24/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(130), mapValueY(300+30), 0.0);
    glVertex3f (mapValueX(225), mapValueY(400+30), 0.0);
    glVertex3f (mapValueX(320), mapValueY(300+30), 0.0);
    glEnd();

    glColor3f (42/255.0, 143/255.0, 14/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(130), mapValueY(350+30), 0.0);
    glVertex3f (mapValueX(225), mapValueY(450+30), 0.0);
    glVertex3f (mapValueX(320), mapValueY(350+30), 0.0);
    glEnd();

    glColor3f (34/255.0, 161/255.0, 38/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(130), mapValueY(400+30), 0.0);
    glVertex3f (mapValueX(225), mapValueY(500+30), 0.0);
    glVertex3f (mapValueX(320), mapValueY(400+30), 0.0);
    glEnd();

    glColor3f (54/255.0, 224/255.0, 60/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(130), mapValueY(450+30), 0.0);
    glVertex3f (mapValueX(225), mapValueY(550+30), 0.0);
    glVertex3f (mapValueX(320), mapValueY(450+30), 0.0);
    glEnd();

    glColor3f (255/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
        glVertex2f (mapValueX(10*cos(degToRad(i))+170),mapValueY(10*sin(degToRad(i))+345));
    }
    glEnd();
}


void mountain(void){
    glColor3f (209/255.0, 108/255.0, 41/255.0);
    glBegin(GL_POLYGON);
    glVertex3f (mapValueX(0), mapValueY(330-20), 0.0);  //a
    glVertex3f (mapValueX(100), mapValueY(450-20), 0.0);
    glVertex3f (mapValueX(200), mapValueY(330-20), 0.0);

    glVertex3f (mapValueX(200), mapValueY(480-20), 0.0);
    glVertex3f (mapValueX(400), mapValueY(330-20), 0.0);

    glVertex3f (mapValueX(400), mapValueY(500-20), 0.0);
    glVertex3f (mapValueX(600), mapValueY(330-20), 0.0);

    glVertex3f (mapValueX(600), mapValueY(500-20), 0.0);
    glVertex3f (mapValueX(800), mapValueY(330-20), 0.0);

    glVertex3f (mapValueX(800), mapValueY(490-20), 0.0);
    glVertex3f (mapValueX(1000), mapValueY(330-20), 0.0);

    glVertex3f (mapValueX(1000), mapValueY(310-20), 0.0);
    glEnd();
}

void grass(int x,int y){
    glColor3f (4/255.0, 115/255.0, 2/255.0);
    glBegin(GL_POLYGON);
    glVertex2f (mapValueX(x),mapValueY(y));
    glVertex2f (mapValueX(x-5-15),mapValueY(y+25));
    glVertex2f (mapValueX(x-15),mapValueY(y+30));
    glVertex2f (mapValueX(x+5-15),mapValueY(y+25));
    glVertex2f (mapValueX(x),mapValueY(y));
    glEnd();

    glColor3f (7/255.0, 145/255.0, 4/255.0);
    glBegin(GL_POLYGON);
    glVertex2f (mapValueX(x),mapValueY(y));
    glVertex2f (mapValueX(x-5),mapValueY(y+25));
    glVertex2f (mapValueX(x),mapValueY(y+30));
    glVertex2f (mapValueX(x+5),mapValueY(y+25));
    glVertex2f (mapValueX(x),mapValueY(y));
    glEnd();

    glColor3f (11/255.0, 232/255.0, 7/255.0);
    glBegin(GL_POLYGON);
    glVertex2f (mapValueX(x),mapValueY(y));
    glVertex2f (mapValueX(x-5+15),mapValueY(y+25));
    glVertex2f (mapValueX(x+15),mapValueY(y+30));
    glVertex2f (mapValueX(x+5+15),mapValueY(y+25));
    glVertex2f (mapValueX(x),mapValueY(y));
    glEnd();
}

void circle(int x,int y,int radius){
    glColor3f (250/255.0, 250/255.0, 0/255.0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
        glVertex2f (mapValueX(radius*cos(degToRad(i))+x),mapValueY(radius*sin(degToRad(i))+y));
    }
    glEnd();
}

void nouka(){
    int x=620;
    int y=60;
    glLineWidth(5);
    glColor3f (0/255.0, 0/255.0, 0/255.0);
    glBegin(GL_POLYGON);
    glVertex2f(mapValueX(100+x),mapValueY(150-y));
    glVertex2f(mapValueX(300+x),mapValueY(150-y));
    glVertex2f(mapValueX(270+x),mapValueY(125-y));
    glVertex2f(mapValueX(130+x),mapValueY(125-y));
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(mapValueX(710),mapValueY(100));
    glVertex2f(mapValueX(710),mapValueY(200));
    glEnd();
}

double degToRad(int angle){
    return (double)angle*PI/180.0;
}
