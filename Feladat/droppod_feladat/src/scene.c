#include "scene.h"
#include <time.h>
#include <GL/glut.h>
#include "camera.h"

#include <obj/load.h>
#include <obj/draw.h> 
#define n 8
#define m 5
#define b 6
#define TerrH -20



int smokeunloader[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

int smokei = 0;

float ambient_light[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    float diffuse_light[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    float specular_light[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    float position[] = { 4.7f, -5.7f, 9.0f, 1.0f };
int start_process = 0;
typedef	struct  {
    float x;
    float y;
	float z;
}Dropod_Origins_Body;



void init_scene(Scene* scene)
{
	scene->model_rotation = 0.0;
	scene->model_fallspeed = 0.0;
	scene->smoke_rot = 0.0;
    load_model(&(scene->model), "object/Droppod3.obj");
    scene->texture_model = load_texture("textures/TDragoonTextures.png");

	load_model(&(scene->particulse), "object/particles.obj");
	scene->texture_entry = load_texture("textures/Reentry.png"); 
	
	load_model(&(scene->damageTer), "object/damage.obj");
	scene->texture_dt = load_texture("textures/damtex.png"); 
	
	load_model(&(scene->terr), "object/Terrain.obj");
	scene->texture_terr = load_texture("textures/Textureter.png"); 
	
	load_model(&(scene->smoke), "object/smoke.obj");
	scene->texture_smoke = load_texture("textures/smoke.png"); 
	
	load_model(&(scene->skybox), "object/skybox.obj");
	scene->texture_sky = load_texture("textures/sky.png"); 
	
	load_model(&(scene->help), "object/help.obj");
	scene->texture_help = load_texture("textures/help.png");
	
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.7;
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
void draw_help(Scene* scene)
{
	glPushMatrix();
	glTranslatef(32,30,30);
	glRotatef(90,0,0,-1);
	glRotatef(90,0,-1,0);
		glBindTexture(GL_TEXTURE_2D, scene->texture_help);
	draw_model(&(scene->help));
	glPopMatrix();
	}
void draw_scene(const Scene* scene)
{

    set_material(&(scene->material));
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	
}
void draw_pods_interain(Scene* scene){
	Dropod_Origins_Body DropPod_InTerrain[b] =
{
	{-3,-11,TerrH},{-5,-9,TerrH},{8,-2,TerrH},{8,3,TerrH},{-5,9,TerrH},{-3,11,TerrH},
};
int i;
for(i=0; i<b;i++){
	glPushMatrix();
	glTranslatef(DropPod_InTerrain[i].x,DropPod_InTerrain[i].y,DropPod_InTerrain[i].z);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
	glPopMatrix();}
}
void draw_pods_insmoke(Scene* scene)
{
	Dropod_Origins_Body DropPod_InActions[m] = 
{
	{3,11,TerrH},{5,9,TerrH},{-10,0,TerrH},{5,-9,TerrH},{3, -11 ,TerrH},
};
int i;
	for(i=0; i<m;i++){
	glPushMatrix();
	glTranslatef(DropPod_InActions[i].x,DropPod_InActions[i].y,DropPod_InActions[i].z);
		glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
			draw_model(&(scene->damageTer));
	glPopMatrix();
	if(smokeunloader[i] == 0){
	glPushMatrix();
	glTranslatef(DropPod_InActions[i].x,DropPod_InActions[i].y,DropPod_InActions[i].z+1);
		glBindTexture(GL_TEXTURE_2D, scene->texture_smoke);
	glRotatef(scene->smoke_rot, 1,0,1);
	draw_model(&(scene->smoke));
	glPopMatrix();}}
}
void draw_pods_falling(Scene* scene) 
{ int i;
Dropod_Origins_Body DropPod_Origins[n] = {
	{3, -2, -1},
	{0, 0, 0},
	{-3, 5, 1},
    {-2, 2, 2},
    {-4, -4, 2},
	{-5, 0, 4},
	{5, 1 , 4},
	{4, 4 , 6},
};
	for(i = 0; i<n;i++){
		if (DropPod_Origins[i].z+scene->model_fallspeed>TerrH+1)
		{
		glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,DropPod_Origins[i].z+scene->model_fallspeed);
	glRotatef(scene->model_rotation, 0,0,1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glPopMatrix();
	glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,DropPod_Origins[i].z+scene->model_fallspeed);
	glRotatef(scene->model_rotation * 2, 0,0,-1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_entry);
	draw_model(&(scene->particulse));
	glPopMatrix();
	}	

		else
			{
	if(smokeunloader[i+m] == 0)
	{glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,TerrH+1);
	glBindTexture(GL_TEXTURE_2D, scene->texture_smoke);
	glRotatef(scene->smoke_rot, 1,0,1);
	draw_model(&(scene->smoke));
	glPopMatrix();}
	glPushMatrix();
	glTranslatef(DropPod_Origins[i].x,DropPod_Origins[i].y,TerrH);
	glBindTexture(GL_TEXTURE_2D, scene->texture_model);
	draw_model(&(scene->model));
	glBindTexture(GL_TEXTURE_2D, scene->texture_dt);
	draw_model(&(scene->damageTer));
	glPopMatrix();
	
}
}
}
void draw_terrain(Scene* scene){
	glPushMatrix();
	glTranslatef(0,0,TerrH);
	glBindTexture(GL_TEXTURE_2D, scene->texture_sky);
	draw_model(&(scene->skybox));
	glBindTexture(GL_TEXTURE_2D, scene->texture_terr);
	draw_model(&(scene->terr));
	glPopMatrix();
}
void update_start_proc(Scene* scene)
{
	scene->start_process = 1;
}
void update_scene(Scene* scene, double time)
{
	int speed =0;
	if (scene->start_process == 1){ speed = 2;}
	scene->model_rotation +=30 * time;
	scene->model_fallspeed -=speed * time;
	scene->smoke_rot += 100 *time;
}

void unloadsmokes()
{	
	int smokesucces = 0;
	static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;
	if(elapsed_time >= 1){
	smokesucces =1;
	}
	if (smokesucces == 1 && smokei<n+m)
	{ 
smokeunloader[smokei]=1;
smokei++;
}
		
}

void set_model_rotation_speed(Scene* scene, double speed)
{
    scene->model_rotation += speed;
}
void modify_light(double delta){
	
	if (ambient_light[0] < 0.7)
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
