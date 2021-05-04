#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model model;
	Model particulse;
	Model damageTer;
	Model terr;
	Model smoke;
	Model skybox;
	Model help;
	float model_rotation;
	float model_fallspeed;
	float smoke_rot;
    Material material;
	GLuint texture_sky;
    GLuint texture_model;
	GLuint texture_entry;
	GLuint texture_dt;
	GLuint texture_terr;
	GLuint texture_smoke;
	GLuint texture_help;

} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void modify_light(double delta);
/**
 * Set the current material.
 */
void set_material(const Material* material);

void update_scene(Scene* scene, double time);
/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);
/**
*Modifies model rotation speed.
*/
void set_model_rotation_speed(Scene* scene, double speed);
/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();
/**
* Unloads smokes on command.
*/ 
void unloadsmokes();
/**
* Draws help
*/
void draw_help();
/**
* Starts the models
*/
void update_start_proc();


#endif /* SCENE_H */
