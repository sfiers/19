#include "wolf.h"

double toa(double angle, double o)
{
	double a;

	a = o / tan((2 * (double)M_PI) / (360 / angle));

	return (a);
}

double ft_deg2rad(double degree)
{
    return (degree * M_PI/180);
}

double ft_rad2deg(double rad)
{
    return (rad / (PI/180.0));
}

void ray(t_ray *ray, t_p a, t_p b)
{
	double temp;

	temp = 0;
	if (b.x - a.x == 0)
		temp = 0.0000001;
	ray->m = (b.y - a.y) / (b.x - a.x + temp); // y = mx + b
	ray->n = b.y - (ray->m * b.x);
	// printf("ray->m = %f\n", ray->m);
	// printf("ray->n = %f\n", ray->n);
}

double distance_2_points(t_p a, t_p b)
{
	// // // // printf("%f %f %f %f\n", a.x, a.y, b.x, b.y);
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

void find_y(t_p *a, double m, double n)
{
	a->y = (m * a->x) + n;
	// if ((int)a->y % 64 == 1)
	// 	a->y -= 1;
	// else if ((int)a->x % 64 == 2)
	// 	a->y -= 2;
	// else if ((int)a->x % 64 == 59)
	// 	a->y += 1;
	// else if ((int)a->x % 64 == 58)
	// 	a->y += 2;
	// // // // printf("a->y %f\n", a->y);
	return;
}

void find_x(t_p *a, double m, double n)
{
	a->x = (a->y - n) / m;
	// if ((int)a->x % 64 == 1)
	// 	a->x -= 1;
	// else if ((int)a->x % 64 == 2)
	// 	a->x -= 2;
	// else if ((int)a->x % 64 == 59)
	// 	a->x += 1;
	// else if ((int)a->x % 64 == 58)
	// 	a->x += 2;
	return;
}

int bloc_to_map(double position, double blocksize)
{
	return(floor((int)position / (int)blocksize));
} 

double ft_distancepointdroite(t_p p, t_droite e)
{
	return(fabs((e.a * p.x + e.b * p.y + e.c) / sqrt(pow(e.a, 2) + pow(e.b, 2))));
}
