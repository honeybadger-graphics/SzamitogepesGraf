#include "scene.h"
#include <math.h>
#include <GL/glut.h>

void init_scene(Scene* scene)
{
}

void draw_scene(const Scene* scene)
{
	draw_origin();
        //draw_triangle(); 
        //draw_sphere();
        //draw_cone();
        draw_cylinder();
       //draw_chesstable();
}



void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
void draw_triangle()
{
    glBegin(GL_TRIANGLES);

    glColor3f(1, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 1);

    glColor3f(0, 1, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(1, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 1);

    glEnd();
}
void draw_sphere()
{
    glColor3f(0.3,0.3,0.3);
GLUquadric *quad;
quad = gluNewQuadric();
glTranslatef(0.5,0.5,0.5);
gluSphere(quad,0.5,25,10);
}
void draw_cone()
{
 glColor3d(1,1,1);
 glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.5,0.5,0.75);
    glVertex3f(0.017,0.629,0);
    glVertex3f(0.146,0.854,0.0);
	glVertex3f(0.371,0.983,0.0);
	glVertex3f(0.629,0.983,0.0);
	glVertex3f(0.854,0.854,0.0);
    glVertex3f(0.983,0.629,0.0);
	glVertex3f(0.983,0.371,0.0);
	glVertex3f(0.854,0.146,0.0);
	glVertex3f(0.629,0.017,0.0);
	glVertex3f(0.371,0.017,0.0);
	glVertex3f(0.146,0.146,0.0);
	glVertex3f(0.017,0.371,0.0);
	glVertex3f(0.017,0.629,0.0);
 glEnd();
 glColor3d(1,0,1);
 glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.017,0.629,0);
    glVertex3f(0.146,0.854,0.0);
	glVertex3f(0.371,0.983,0.0);
	glVertex3f(0.629,0.983,0.0);
	glVertex3f(0.854,0.854,0.0);
    glVertex3f(0.983,0.629,0.0);
	glVertex3f(0.983,0.371,0.0);
	glVertex3f(0.854,0.146,0.0);
	glVertex3f(0.629,0.017,0.0);
	glVertex3f(0.371,0.017,0.0);
	glVertex3f(0.146,0.146,0.0);
	glVertex3f(0.017,0.371,0.0);
	glVertex3f(0.017,0.629,0.0);
 glEnd();
 glFlush();
}
void draw_chesstable()
{

int i ;
int j;
float color0 = 0;
float color1 = 1;
float y = 0; 
for(j=0;j<8;j++){
float x = 0;
for(i=0;i<4;i++){
 glColor3d(color0,color0,color0);
 glBegin(GL_QUADS);
    glVertex3f(x,y,0);
    glVertex3f(x+0.125,y,0);
	glVertex3f(x+0.125,y+0.125,0);
	glVertex3f(x,y+0.125,0);
 glEnd();
 glColor3d(color1,color1,color1);
 glBegin(GL_QUADS);
    glVertex3f(x+0.125,y,0);
    glVertex3f(x+0.125,y+0.125,0);
	glVertex3f(x+0.25,y+0.125,0);
	glVertex3f(x+0.25,y,0);
glEnd();
x= x+ 0.25;
}
y=y+0.125;
/*use help to change up the colors*/
float help;
help = color0;
color0 = color1;
color1= help;
}



 glFlush();
}
void draw_cylinder()
{float x=0.5;
float y = 0;
float z =0.5;
float r = 0.5;
float HEIGHT = 1;
int slices = 16;
int i;
glColor3d(0.3,0.3,0.3);
 glBegin(GL_TRIANGLE_FAN);
// bottom circle
glVertex3f(x,y,z);
for(i=0; i<=slices; i++) {glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,
y, z+sin((float)i/slices * 2 * M_PI)*r);}
glEnd();

glBegin(GL_TRIANGLE_FAN);
//top circle
glVertex3f(x,y + HEIGHT,z);
for(i=0; i<=slices; i++) {glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,
y+ HEIGHT, z+sin((float)i/slices * 2 * M_PI)*r);}
glEnd();

// the rest of the cylinder
glColor3d(1,1,1);
glBegin(GL_TRIANGLE_STRIP);
for(i=0; i<=slices; i++) 
{
   glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,y, z+sin((float)i/slices * 2 * M_PI)*r);
   glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,y+ HEIGHT, z+sin((float)i/slices * 2 * M_PI)*r);
}
glEnd();
 glFlush();

}
