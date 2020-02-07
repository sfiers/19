#include "wolf.h"

void fill_info(t_info *info)
{
	info->blocksize = 64;
	info->screenWidth = 320;
	info->screenHeight = 200;
	info->pov = 66;
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
// 	int i;
// 	int j;
// 	int map[24][24] = 
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, // 0
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 1
//   {1,0,5,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 2
//   {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,1,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 5
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,1,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 10
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 15
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {0,1,1,1,1,1,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,1,4,4,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 20
//   {1,0,5,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,1,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // 23 
// };
// 	info->worldMap2 = map;
// 	for(j=0; j < 24; j++)
//   	{
//     for(i = 0; i < 24; i++)
//     {
//       printf("%d",info->worldMap2[j][i]);
//     }
//     printf("\n");
// 	}
}

void	ft_display(t_info *info, mlx_ptr_t *s, int whichray, float distance) // probablenent suppr float distance
{
	int		y;
	//float	slice_hight;
	float	wall_down;
	y = 0;
	// distance = 150;
	wall_down = (info->screenHeight - distance) / 2;
	while (y < info->screenHeight)
	{
		while (y < wall_down) //plafond
		{
			mlx_pixel_put(s->mlx, s->win, whichray, y, 0x87ceff);
			y++;
		}
		while (y < (wall_down + distance)) //mur
		{
			mlx_pixel_put(s->mlx, s->win, whichray, y, 0xcd853f);
			y++;
		}
		mlx_pixel_put(s->mlx, s->win, whichray, y, 0x54ff9f);  //sol
		y++;
	}
}

int	main()
{
	t_info info;
	mlx_ptr_t s;
	t_maptab	tab;
	int whichray;
	float distance;
	float slice_hight;
	
	parsing(&tab);
	info.worldMap = tab.tab;
	whichray = 13;
	info.angle = 0;
	fill_info(&info);
	s.mlx = mlx_init();
    s.win = mlx_new_window(s.mlx, info.screenWidth, info.screenHeight, "new window !");
	//s.img = mlx_new_image(s.mlx, info.screenWidth, info.screenHeight);
	while (info.angle != 360)
	{
	while(whichray < info.screenWidth) //info.screenWidth
	{
		printf("ray = %d\n", whichray);
		p_on_plan(&info, (float)whichray); // calcule le point sur le plan par ou passe le rayon
		ray(&info.ray, info.a, info.p_of_plan);
		printf("--------------x---------------\n");
		test_x_axis(&info);
		
		printf("--------------y---------------\n");

		test_y_axis(&info);
		printf("--------------result---------------\n");
		// printf("distance = %f\n", distance_to_wall(&info)); // tu peux essayer avec cette distance la (fish)
		// distance = walls(&info, distance, whichray); // et puis avec celle si, j'ai pas pu tes mais ca pourrait etre correct
		distance = distance_to_wall(&info);
		printf("distance %f\n", distance);	
		slice_hight = walls(&info, distance, whichray);
				
		printf("														slice_hight = %f\n", slice_hight);
		ft_display(&info, &s, whichray, slice_hight);
		//implementer pour dans pixelput ou whatever it's called;
		// printf("    x = %d\n", info.map[1].x);
		// printf("    y = %d\n", info.map[1].y);		
		whichray++;
		// printf("-------------------------------\n");
		// printf("-------------------------------\n");
	
		// break;
	}
	info.angle+= 2;
	}
	//	mlx_put_image_to_window(s.mlx, s.win, s.img, info.screenWidth, info.screenHeight);
	//mlx_key_hook(s.win, ft_moove, &info);
// /	mlx_key_hook(s.win, ft_angle, &info);
//	mlx_loop_hook(s.mlx);
	//mlx_hook(s.win, 2, 1L<<0, ft_angle, &s);
//	mlx_hook(s.win, 3, 1L<<1, ft_angle, &s);
	mlx_hook(s.win, 2, 1L<<0, ft_close, &s); //fermer la fenetre, 0xffff);  //imprimer pixel
    mlx_loop(s.mlx);
}

void p_on_plan(t_info *info, float whichray)
{
	info->p_of_plan.x = info->b.x - (whichray * (info->b.x - info->c.x) / info->screenWidth);
	info->p_of_plan.y = info->b.y - (whichray * (info->b.y - info->c.y) / info->screenWidth);
}

void test_x_axis(t_info *info)
{
	int hit;
	int n;
	// int i;
	// int j;
	
	n = 0;
	hit = 0;
	// 	for(j=0; j < 24; j++)
  	// {
    // for(i = 0; i < 24; i++)
    // {
    //   printf("%d",info->worldMap[j][i]);
    // }
    // printf("\n");
	// }
	info->redflag[0] = 0;
	info->test_axis[n].x = (info->a.x < info->p_of_plan.x) ? info->next_axis[n] : info->next_axis[n] - info->blocksize;
	while (hit == 0)
	{
		find_y(&info->test_axis[n], info->ray.m, info->ray.n);
		printf("info->test_axis[0] = %f\n", info->test_axis[n].x);
		printf("info->test_axis[0] = %f\n", info->test_axis[n].y);
		if (map_bounderies(info, n) == 1)
			break;
		if((hit = hit_map(info, n) == 1))
			break;
		info->test_axis[n].x += (info->a.x < info->p_of_plan.x) ? info->blocksize : - info->blocksize;
	}
}

void test_y_axis(t_info *info)
{
	int hit;
	int n;
	
	n = 1;
	hit = 0;
	info->redflag[1] = 0;
	info->test_axis[n].y = (info->a.y < info->p_of_plan.y) ? info->next_axis[n] : info->next_axis[n] - info->blocksize;
	while (hit == 0)
	{
		find_x(&info->test_axis[n], info->ray.m, info->ray.n);
		printf("info->test_axis[1] = %f\n", info->test_axis[n].x);
		printf("info->test_axis[1] = %f\n", info->test_axis[n].y);
		if (map_bounderies(info, n) == 1)
			break;
		if((hit = hit_map(info, n) == 1))
			break;
		info->test_axis[n].y += (info->a.y < info->p_of_plan.y) ? info->blocksize : - info->blocksize;
	}
}

int map_bounderies(t_info *info, int n)
{
	if ((int)info->test_axis[n].x < 0 || (int)info->test_axis[n].y < 0)
	{
		info->redflag[n] = 1;
		printf("info->redflag[n] = %d\n", info->redflag[n]);
		return (1);
	}
	if ((int)info->test_axis[n].x > (int)(mapHeight * info->blocksize) || (int)info->test_axis[n].y > (int)(mapWidth * info->blocksize))
	{
		info->redflag[n] = 1;
		printf("info->redflag[n] = %d\n", info->redflag[n]);
		return (1);
	}
	return (0);
}

float distance_to_wall(t_info *info)
{
	float distance[2];

	if (info->redflag[0] == 1)
	{
		printf("--------------1--------------\n");
		printf("distance[0] %f\n", distance[0]);
		printf("distance[1] %f\n", distance_2_points(info->a, info->test_axis[1]));
		return (distance_2_points(info->a, info->test_axis[1]));
	}
	if (info->redflag[1] == 1)
	{
		printf("--------------2--------------\n");
		printf("distance[0] %f\n", distance[0]);
		printf("distance[1] %f\n", distance[1]);
		return (distance_2_points(info->a, info->test_axis[0]));
	}
	distance[0] = distance_2_points(info->a, info->test_axis[0]); // pour les x
	distance[1] = distance_2_points(info->a, info->test_axis[1]); 
	printf("distance[0] %f\n", distance[0]);
	printf("distance[1] %f\n", distance[1]);
	printf("--------------distance to be used---------------\n");
	if (distance[0] < distance[1])
		return (distance[0]);
	else 
		return (distance[1]); 
}

float hit_map(t_info *info, int n)
{
	info->map[0].x = (info->a.x < info->p_of_plan.x) ? bloc_to_map(info->test_axis[n].x, info->blocksize) : bloc_to_map(info->test_axis[n].x, info->blocksize) - 1;
	info->map[0].y = bloc_to_map(info->test_axis[n].y, info->blocksize);
	info->map[1].x = bloc_to_map(info->test_axis[n].x, info->blocksize);
	info->map[1].y = (info->a.y < info->p_of_plan.y) ? bloc_to_map(info->test_axis[n].y, info->blocksize) : bloc_to_map(info->test_axis[n].y, info->blocksize) - 1;
	printf("map A = %d\n", (mapHeight - 1) - info->map[n].y);
	printf("map B = %d\n", info->map[n].x);
	printf("test x = %d\n", info->map[1].x);
	printf("test y = %d\n", info->map[1].y);	
	if (info->worldMap[(mapWidth - 1) - info->map[n].y][info->map[n].x] == 1) // because our map y-axis is reversed (to be checked if mapWidth and not mapHeight)
		return (1);
	return(0);
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
