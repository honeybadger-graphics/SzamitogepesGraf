#include "scene.h"

#include <GL/glut.h>

void init_scene(Scene* scene)
{
}

void draw_scene(const Scene* scene)
{
    draw_origin();
	draw_triangle();
	draw_sphere();
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
    glColor3f(1,0,0);
GLUquadric *quad;
quad = gluNewQuadric();
glTranslatef(0.5,0.5,0.5);
gluSphere(quad,0.5,100,20);
}
