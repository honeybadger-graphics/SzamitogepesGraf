#include "scene.h"
#include <math.h>
#include <GL/glut.h>

void init_scene(Scene* scene)
{
}

void draw_scene(const Scene* scene)
{
    draw_origin();
	/*draw_triangle(); works just remove comment*/
	/*draw_sphere(); works just remove comment*/
	/*draw_cone(); same as above*/
	draw_cylinder();
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
void draw_cylinder()
{float x=0.5;
float y = 0;
float z =0.5;
float r = 0.5;
float HEIGHT = 1;
int slices = 16;
int i;
glColor3d(1,1,1);
 glBegin(GL_TRIANGLE_FAN);
// bottom circle
glVertex3f(x,y,z);
for(i=0; i<slices; i++) {glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,
y, z+sin((float)i/slices * 2 * M_PI)*r);}
glEnd();

glBegin(GL_TRIANGLE_FAN);
//top circle
glVertex3f(x,y + HEIGHT,z);
for(i=0; i<slices; i++) {glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,
y+ HEIGHT, z+sin((float)i/slices * 2 * M_PI)*r);}
glEnd();

// the rest
glBegin(GL_TRIANGLE_STRIP);
for(i=0; i<=slices; i++) 
{
   glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,y, z+sin((float)i/slices * 2 * M_PI)*r);
   glVertex3f(x + cos((float)i/slices * 2 *M_PI)*r,y+ HEIGHT, z+sin((float)i/slices * 2 * M_PI)*r);
}
glEnd();
 glFlush();

}
