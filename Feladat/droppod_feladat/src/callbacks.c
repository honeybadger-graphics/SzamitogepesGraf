#include "callbacks.h"

#define VIEWPORT_RATIO (5.0 / 3.0)
#define VIEWPORT_ASPECT 45.0

struct {
    int x;
    int y;
} mouse_position;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&camera);
	draw_help(&scene);
	draw_scene(&scene);
	draw_terrain(&scene);
	draw_pods_falling(&scene);
	draw_pods_insmoke(&scene);
	draw_pods_interain(&scene);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEWPORT_ASPECT, VIEWPORT_RATIO, 0.01, 10000.0);
}

void mouse(int button, int state, int x, int y)
{
    mouse_position.x = x;
    mouse_position.y = y;
}

void motion(int x, int y)
{
    rotate_camera(&camera, mouse_position.x - x, mouse_position.y - y);
    mouse_position.x = x;
    mouse_position.y = y;
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{

    switch (key) {
    case 'w':
        set_camera_speed(&camera, 1);
        break;
    case 's':
        set_camera_speed(&camera, -1);
        break;
    case 'a':
        set_camera_side_speed(&camera, 1);
        break;
    case 'd':
        set_camera_side_speed(&camera, -1);
        break;
	case'y':
		set_camera_height_speed(&camera, 1);
	break;
	case 'x':
	set_camera_height_speed(&camera, -1);
	break;
	case 13:
	restoretodefcam(&camera);
	update_start_proc(&scene);
	break;
	case 'r':
	unloadsmokes();
	break;
	case'h':
	showhelp(&camera);
	break;
	case '+':
	modify_light(0.01);
	break;
	case '-':
	modify_light(-0.01);
	break;
	case 'e':
		set_model_rotation_speed(&scene, 2);
		break;
	case 'q':
		set_model_rotation_speed(&scene, -0.75);
		break;
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
    case 's':
        set_camera_speed(&camera, 0.0);
        break;
    case 'a':
    case 'd':
        set_camera_side_speed(&camera, 0.0);
        break;
	case'h':
	restoretodefcam(&camera);
	break;
	case'+':
	case'-':
		modify_light(0);
		break;
	case'x':
	case'y':
	set_camera_height_speed(&camera, 0);
	break;
    }

    glutPostRedisplay();
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_camera(&camera, elapsed_time);
	update_scene(&scene, elapsed_time);

    glutPostRedisplay();
}
