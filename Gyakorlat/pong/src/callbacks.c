#include "callbacks.h"
#include "draw.h"
#include "ball.h"


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    draw_game(&game);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    resize_game(&game, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -200, 200);
    glViewport(0, 0, width, height);
}

void motion(int x, int y)
{
    move_right_pad(&game, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    float position;

    position = game.left_pad.position;
    switch (key) {
    case 'w':
        position -= 10;
        break;
    case 's':
        position += 10;
        break;
    }
    move_left_pad(&game, position);

    glutPostRedisplay();
}
void keyboardforRad(unsigned char key, int x, int y)
{
    float position;

    position = game.ball.radius;
    switch (key) {
    case '-':
        position = position - 1;
        break;
    case '+':
        position = position + 1;
        break;
    }
    modf_radious_ball(&game, position);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	 int mouseXPos =0;
	 int mouseYPos =0;
    if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON)
    {
		
        if(state == GLUT_DOWN)
		{
			mouseXPos = x;
			mouseYPos = y;
			mouse_move_ball(&game, mouseXPos, mouseYPos);
			glutPostRedisplay();
		}
		
    }
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

    update_game(&game, elapsed_time);
    glutPostRedisplay();
}

