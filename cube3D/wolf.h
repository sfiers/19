#ifndef WOLF_H 
# define WOLF_H


/*
** -------------------------- External Headers ---------------------------------
*/

// # include "../libft/libft.h"
#include <math.h>
#include <stdio.h>

/*
** ------------------------- Structure Definition ------------------------------
*/

typedef struct      s_p
{
	float x;
	float y;
	float z;
}				    t_p;

typedef struct      s_map
{
	int x;
	int y;
	int z;
}				    t_map;

typedef struct		s_ray
{
	float m;
	float n;
}					t_ray;   // y = mx + n

typedef struct      s_info
{
	float blocksize;
	float angle;
	float screenWidth;
	float screenHeight;
	float pov;
	t_p	a;
	t_p	b;
	t_p	c;
	t_p	d;
	t_p	dir;
	t_p plan;
	t_p p_of_plan;
	float ad;
	float bd;
	float bad;
	t_ray ray;
	float next_axis[2];
	t_map map[2]; // x axis = 0 and y axis 1
	t_p test_axis[2];
}				    t_info;




/*
** --------------------------------- Define ------------------------------------
*/

#define PI 3.14159265358979323846264338327950288419716939937510

/*
** -----------------------------------------------------------------------------
** ------------------------------- Sources -------------------------------------
** -----------------------------------------------------------------------------
*/
void fill_info(t_info *info);
void print(t_info *info); // delete this crap

/*
** --------------------------- Parsing Functions -------------------------------
*/


/*
** ------------------------------ conversions ----------------------------------
*/

int bloc_to_map(float position, float blocksize);


/*
** ----------------------------- Maths Functions -------------------------------
*/

float toa(float angle, float o);
float distance_to_previous_axis(t_info info, float blocksize);
float m(t_p a, t_p b);
float hit_map(t_info *info, int n);
float distance_2_points(t_p a, t_p b);
float distance_to_wall(t_info *info);
void test_x_axis(t_info *info);
void ray(t_ray *ray, t_p a, t_p b);
void p_on_plan(t_info *info, float whichray);
float ft_deg2rad(float degree);
void find_y(t_p *a, float m, float n);
void find_x(t_p *a, float m, float n);



/*
** ---------------------- Strings & Chars Functions ----------------------------
*/






#endif