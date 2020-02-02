#include "wolf.h"
#define mapWidth 24
#define mapHeight 24

float worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 0
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 1
  {1,0,5,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 2
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,1,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 5
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,1,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 10
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 15
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,1,1,1,0,4,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 20
  {1,4,5,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // 23 
};

void fill_info(t_info *info)
{
	info->blocksize = 64;
	info->screenWidth = 320;
	info->screenHeight = 200;
	info->pov = 60;
	info->a.x = 160;
	info->a.y = 160;
	info->a.z = 32;
	info->bad = info->pov/2;
	info->bd = info->screenWidth / 2;
	info->ad = toa(info->bad, info->bd);
	info->dir.x = round(cos(ft_deg2rad(info->angle)) * info->ad);
	info->dir.y = round(sin(ft_deg2rad(info->angle)) * info->ad);
	info->plan.x = round(cos(ft_deg2rad(info->angle + 90)) * info->bd);
	info->plan.y = round(sin(ft_deg2rad(info->angle + 90)) * info->bd);
	info->b.x = info->a.x + info->dir.x + info->plan.x;
	info->b.y = info->a.y + info->dir.y + info->plan.y;
	info->c.x = info->a.x + info->dir.x - info->plan.x;
	info->c.y = info->a.y + info->dir.y - info->plan.y;
	info->next_axis[0] = info->a.x + ((int)info->a.x % (int)info->blocksize);
	info->next_axis[1] = info->a.y + ((int)info->a.y % (int)info->blocksize);
}



int	main()
{
	t_info info;
	int whichray;
	float distance;

	whichray = 0;
	info.angle = 0;
	fill_info(&info);
	while(whichray < info.screenWidth)
	{
		p_on_plan(&info, whichray); // calcule le point sur le plan par ou passe le rayon
		ray(&info.ray, info.a, info.p_of_plan);
	
		print(&info);
		test_x_axis(&info);


		distance = distance_to_wall(&info);
		printf("distance = %f\n", distance);
		//implementer pour dans pixelput ou whatever it's called;
		printf("info.map[0].x = %d\n", info.map[0].x);
		printf("info.map[0].y = %d\n", info.map[0].y);
	
		break;
		whichray++;
	}
}

float ft_deg2rad(float degree)
{
    return (degree * (PI/180.0));
}

void p_on_plan(t_info *info, float whichray)
{
	info->p_of_plan.x = info->b.x + (whichray * (info->b.x - info->c.x) / info->screenWidth);
	info->p_of_plan.y = info->b.y + (whichray * (info->b.y - info->c.y) / info->screenWidth);
}

void ray(t_ray *ray, t_p a, t_p b)
{
	ray->m = (b.y - a.y) / (b.x - a.x);
	printf("%f\n", (b.y - a.y));
	printf("%f\n", b.x - a.x);
	ray->n = b.y - (ray->m * b.x);
}

void test_x_axis(t_info *info)
{
	int hit;
	int n;
	float temp;
	
	n = 0; // 0 pour x et 1 pour y
	//temp = (n == 0) ? info->test_axis[n].x : info->test_axis[n] // faut changer en .y et incrementer pour le test y 
	hit = 0;
	info->test_axis[n].x = (info->dir.x > 0) ? info->next_axis[n] : info->next_axis[n] - info->blocksize;
	while (hit == 0)
	{
		info->test_axis[n].y = -100;  // pour informer fonction line
		printf("n = %d \n", n);
		find_y(&info->test_axis[n], info->ray.m, info->ray.n);
		printf("info->test_axis[0].x = %f \n", info->test_axis[0].x);
		printf("info->test_axis[0].y = %f \n", info->test_axis[0].y);
		if((hit = hit_map(info, n)) == 1)
			break;
		printf("info->blocksize = %f \n", info->test_axis[n].x);
		info->test_axis[n].x = round(info->test_axis[n].x + info->blocksize);
		printf("info->blocksize = %f \n", info->test_axis[n].x);
	}
	printf("hit %d\n", hit);
}

float distance_to_wall(t_info *info)
{
	float distance[2];
	distance[0] = distance_2_points(info->a, info->test_axis[0]);
	// distance[1] = distance_2_points(info->a, info->test_axis[1]);
	// if (distance[0] < distance[1])
		return (distance[0]);
	// else 
	// 	return (distance[1]); 
}

float distance_2_points(t_p a, t_p b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

float hit_map(t_info *info, int n)
{
	info->map[n].x = bloc_to_map(info->test_axis[n].x, info->blocksize);
	info->map[n].y = bloc_to_map(info->test_axis[n].y, info->blocksize);
	printf("input x = %d\n", (mapHeight - 1) - info->map[n].y);
	printf("input y = %d\n", info->map[n].x);
	// if (worldMap[info->map[n].x][(mapHeight - 1) - info->map[n].y] == 1) // because our map y-axis is reversed
	if (worldMap[(mapHeight - 1) - info->map[n].y][info->map[n].x] == 1) // because our map y-axis is reversed
		return (1);
	return(0);
}

void find_y(t_p *a, float m, float n)
{
	a->y = round((m * a->x) + n);
	return;
}

void find_x(t_p *a, float m, float n)
{
	a->x = round((a->y - n) / m);
	return;
}

void print(t_info *info)
{
	printf("info->b.x = %f\n", info->b.x);
	printf("info->b.y = %f\n", info->b.y);
	printf("info->a.x = %f\n", info->a.x);
	printf("info->a.y = %f\n", info->a.y);
	printf("info.dir.x = %f\n", info->dir.x);
	printf("info.dir.y = %f\n", info->dir.y);
	printf("info->plan.x = %f\n", info->plan.x);
	printf("info->plan.y = %f\n", info->plan.y);		
	printf("p_of_plan.x = %f\n", info->p_of_plan.x);
	printf("p_of_plan.y = %f\n", info->p_of_plan.y);
	printf("info->ray.m = %f\n", info->ray.m);
	printf("info->ray.n = %f\n", info->ray.n);
}