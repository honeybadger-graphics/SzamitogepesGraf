#include "scene.h"
#include <time.h>
#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h> 
#define n 6
#define m 3
#define b 4
#define TerrH -20

float ambient_light[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    float diffuse_light[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    float specular_light[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    float position[] = { 1.0f, 0.0f, 3.0f, 1.0f };


void init_scene(Scene* scene)
{
	scene->model_rotation = 0.0;
	scene->model_fallspeed = 0.0;
	scene->smoke_rot = 0.0;

    load_model(&(scene->model), "Droppod3.obj");
    scene->texture_model = load_texture("TDragoonTextures.png");

	load_model(&(scene->particulse), "particles.obj");
	scene->texture_entry = load_texture("Reentry.png"); 
	
	load_model(&(scene->damageTer), "damage.obj");
	scene->texture_dt = load_texture("damtex.png"); 
	
	load_model(&(scene->terr), "Terrain.obj");
	scene->texture_terr = load_texture("Textureter.png"); 
	
	load_model(&(scene->smoke), "smoke.obj");
	scene->texture_smoke = load_texture("smoke.png"); 
	
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 0.9;
    scene->material.ambient.blue = 9.9;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 0.9;
    scene->material.diffuse.blue = 0.9;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 0.9;
    scene->material.specular.blue = 0.8;

    scene->material.shininess = 0.5;
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
	{3,0,TerrH},{4,2,TerrH},{4,-2,TerrH},
};
Dropod_Origins_Body DropPod_InTerrain[b] =
{
	{5,0,TerrH},{6,2,TerrH},{6,-2,TerrH},{7,0,TerrH},
};
	int i;
	int j;
	int k;
	int unloadsmoke = 0;
    set_material(&(scene->material));
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
    draw_origin();
	printf("%f\n", ambient_light[0]);
	glPushMatrix();
	glTranslatef(0,0,TerrH);
	glBindTexture(GL_TEXTURE_2D, scene->texture_terr);
	draw_model(&(scene->terr));
	glPopMatrix();
	for(i = 0; i<n;i++){
		if (DropPod_Origins[i].z+scene->model_fallspeed>TerrH+1)
		{
		glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,DropPod_Origins[i].z+scene->model_fallspeed);
	glRotatef(scene->model_rotation, 0,0,1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glPopMatrix();}	

		else
			{
	glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,TerrH+1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_smoke);
	glRotatef(scene->smoke_rot, 1,0,1);
	draw_model(&(scene->smoke));
	glPopMatrix();
	glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,TerrH);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glPopMatrix();
	unloadsmoke = 1;
	}	
		}
	
	for(j = 0; j<n;j++){
		if (DropPod_Origins[i].z+scene->model_fallspeed>TerrH)
		{
	glPushMatrix();
	glTranslatef(DropPod_Origins[j].x,DropPod_Origins[j].y,DropPod_Origins[j].z+scene->model_fallspeed);
	glRotatef(scene->model_rotation, 0,0,-1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_entry);
	draw_model(&(scene->particulse));
	glPopMatrix();}
	}
	for(k=0;k<n;k++)
	{
		if(DropPod_Origins[k].z+scene->model_fallspeed<TerrH)
		{
			glPushMatrix();
			glTranslatef(DropPod_Origins[k].x,DropPod_Origins[k].y,TerrH);
			glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
			glPopMatrix();
		}
	}
	
	for(i=0; i<m;i++){
	glPushMatrix();
	glTranslatef(DropPod_InActions[i].x,DropPod_InActions[i].y,DropPod_InActions[i].z);
		glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
	glPopMatrix();
	if(unloadsmoke == 0){
	glPushMatrix();
	glTranslatef(DropPod_InActions[i].x,DropPod_InActions[i].y,DropPod_InActions[i].z+1);
		glBindTexture(GL_TEXTURE_2D, scene->texture_smoke);
	glRotatef(scene->smoke_rot, 1,0,1);
	draw_model(&(scene->smoke));
	glPopMatrix();}}
	
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
	scene->model_rotation +=20 * time;
	scene->model_fallspeed -= 2 * time;
	scene->smoke_rot += 50 *time;
}

void set_model_rotation_speed(Scene* scene, double speed)
{
    scene->model_rotation += speed;
}
void modify_light(double delta){
	
	if (ambient_light[0] < 0.6)
			ambient_light[0] = ambient_light[1] = ambient_light[2] += delta;
			specular_light[0] = specular_light[1] = specular_light[2] += delta;
			specular_light[0] = specular_light[1] = specular_light[2] += delta;
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
