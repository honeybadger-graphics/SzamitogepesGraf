#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h> 
#define n 6
#define m 3
#define b 4

void init_scene(Scene* scene)
{
	scene->cube_rotation = 0.0;
	scene->cube_fallspeed = 0.0;

    load_model(&(scene->model), "Droppod3.obj");
    scene->texture_model = load_texture("TDragoonTextures.png");

	load_model(&(scene->particulse), "particles.obj");
	scene->texture_entry = load_texture("Reentry.png"); 
	
	load_model(&(scene->damageTer), "damage.obj");
	scene->texture_dt = load_texture("damtex.png"); 
	
	load_model(&(scene->terr), "Terrain.obj");
	scene->texture_terr = load_texture("Textureter.png"); 
    

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
    {-1, 2, 1},
    {-1, -2, 1},
	{-2.5, 0, 2},
	{-3, 4, -0.75},
	{-3, -4, 1.5},
};
Dropod_Origins_Body DropPod_InActions[m] = 
{
	{3,0,-10},{4,2,-10},{4,-2,-10},
};
Dropod_Origins_Body DropPod_InTerrain[b] =
{
	{5,0,-10},{6,2,-10},{6,-2,-10},{7,0,-10},
};
	int i;
	int j;
	int k;
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
	glPushMatrix();
	glTranslatef(0,0,-10);
	glBindTexture(GL_TEXTURE_2D, scene->texture_terr);
	draw_model(&(scene->terr));
	glPopMatrix();
	for(i = 0; i<n;i++){
	glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,DropPod_Origins[i].z+scene->cube_fallspeed);
	glRotatef(scene->cube_rotation, 0,0,1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glPopMatrix();}
	for(j = 0; j<n;j++){
	glPushMatrix();
	glTranslatef(DropPod_Origins[j].x,DropPod_Origins[j].y,DropPod_Origins[j].z+scene->cube_fallspeed);
	glRotatef(scene->cube_rotation, 0,0,-1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_entry);
	draw_model(&(scene->particulse));
	glPopMatrix();}
	for(k=0;k<n;k++)
	{
		if(DropPod_Origins[k].z+scene->cube_fallspeed<-10)
		{
			glPushMatrix();
			glTranslatef(DropPod_Origins[k].x,DropPod_Origins[k].y,-10);
			glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
			glPopMatrix();
		}
	}
	for(i=0; i<m;i++){
	glPushMatrix();
	glTranslatef(DropPod_InActions[i].x,DropPod_InActions[i].y,DropPod_InActions[i].z);
	glRotatef(scene->cube_rotation, 0,1,0); //placeholder for if they are inpacting furface
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
	glPopMatrix();}
	for(i=0; i<b;i++){
	glPushMatrix();
	glTranslatef(DropPod_InTerrain[i].x,DropPod_InTerrain[i].y,DropPod_InTerrain[i].z);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
	glPopMatrix();}
}
void update_scene(Scene* scene, double time)
{
	scene->cube_rotation += 10.0* time;
	scene->cube_fallspeed-= 1.0* time;
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
