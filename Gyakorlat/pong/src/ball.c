#include "ball.h"

void move_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
}

void start_ball(Ball* ball, float x, float y)
{
    ball->radius = 50;
    move_ball(ball, x, y);
    ball->speed_x = 500;
    ball->speed_y = 500;
}
void rad_ball(Ball* ball, float r)
{
	float maxlimit = 75;
	float minlimit = 25;
	if(ball->radius>= minlimit && ball->radius <= maxlimit)  
	{	
		ball->radius = r;
	}
	else
	{
		ball->radius = ball->radius;
	}
}

void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
}

