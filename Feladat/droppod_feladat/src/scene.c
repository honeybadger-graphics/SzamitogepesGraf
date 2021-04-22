#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h> 
#define n 5

void init_scene(Scene* scene)
{
	scene->cube_rotation = 0.0;
	scene->cube_fallspeed = 0.0;

    load_model(&(scene->cube), "droppod3.obj");
load_model(&(scene->particulse), "particulse.obj");
    scene->texture_id = load_texture("TDragoonTextures.png"); 

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.5;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 2.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{
typedef	struct  {
    float x;
    float y;
	float z;
}Dropod_Origins_Body;

Dropod_Origins_Body DropPod_Origins[n] = {
	{0, 0, 0},
    {1, 2, 1},
    {-3, -2, 1},
	{1.5, 3, -0.75},
	{1, -4, 1.5},
};
	int i;
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
	for(i = 0; i<n;i++){
	glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,DropPod_Origins[i].z);
	glRotatef(scene->cube_rotation, 0,0,1);
	draw_model(&(scene->cube));
	draw_model(&(scene->particulse));
	glPopMatrix();}
}
void update_scene(Scene* scene, double time)
{
	scene->cube_rotation += 10.0* time;
	scene->cube_fallspeed+= 10.0*time;
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
