#include "wolf.h"

float toa(float angle, float o)
{
	float a;

	a = o / tan((2 * (float)PI) / (360 / angle));

	return (a);
}

float ft_deg2rad(float degree)
{
    return (degree * (PI/180.0));
}

void ray(t_ray *ray, t_p a, t_p b)
{
	float temp;

	temp = 0;
	if (b.x - a.x == 0)
		temp = 0.0000001;
	ray->m = (b.y - a.y) / (b.x - a.x + temp); // y = mx + b
	ray->n = b.y - (ray->m * b.x);
}

float distance_2_points(t_p a, t_p b)
{
	// printf("%f %f %f %f\n", a.x, a.y, b.x, b.y);
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

void find_y(t_p *a, float m, float n)
{
	a->y = round((m * a->x) + n);
	// printf("a->y %f\n", a->y);
	return;
}

void find_x(t_p *a, float m, float n)
{
	a->x = round((a->y - n) / m);
	return;
}

int bloc_to_map(float position, float blocksize)
{
	return(floor((int)position / (int)blocksize));
} 