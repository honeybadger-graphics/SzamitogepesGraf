#include "callbacks.h"
#include "init.h"

#include <GL/glut.h>

#include <stdio.h>

/**
 * Set the callbacks for GLUT.
 */
void set_callbacks()
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutIdleFunc(idle);
}

/**
 * Main function
 */
int main(int argc, char* argv[])
{
    int window;

    glutInit(&argc, argv);

    glutInitWindowSize(1024, 768);     
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    window = glutCreateWindow("DropPod");
    glutSetWindow(window);

    init_opengl();
    init_scene(&scene);
    init_camera(&camera);
    set_callbacks();

    glutMainLoop();

    return 0;
}
