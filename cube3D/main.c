#include "wolf.h"

void fill_info(t_info *info)
{
	info->blocksize = 64;
	info->screenWidth = 1280;
	info->screenHeight = 800;
	info->pov = 66;
	info->a.x = 160;
	info->a.y = 160;
	info->angle = 0; // link to input NESW
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
	info->next_axis[0] = (int)info->a.x + (int)info->blocksize - ((int)info->a.x % (int)info->blocksize);
	info->next_axis[1] = (int)info->a.y + (int)info->blocksize - ((int)info->a.y % (int)info->blocksize);
}

void update_info(t_info *info)
{
	info->dir.x = round(cos(ft_deg2rad(info->angle)) * info->ad);
	info->dir.y = round(sin(ft_deg2rad(info->angle)) * info->ad);
	info->plan.x = round(cos(ft_deg2rad(info->angle + 90)) * info->bd);
	info->plan.y = round(sin(ft_deg2rad(info->angle + 90)) * info->bd);
	info->b.x = info->a.x + info->dir.x + info->plan.x;
	info->b.y = info->a.y + info->dir.y + info->plan.y;
	info->c.x = info->a.x + info->dir.x - info->plan.x;
	info->c.y = info->a.y + info->dir.y - info->plan.y;
	info->next_axis[0] = (int)info->a.x + (int)info->blocksize - ((int)info->a.x % (int)info->blocksize);
	info->next_axis[1] = (int)info->a.y + (int)info->blocksize - ((int)info->a.y % (int)info->blocksize);
	printf("info->next_axis[0] = %f\n", info->next_axis[0]);
	printf("info->next_axis[1] = %f\n", info->next_axis[1]);
}

void	ft_display(t_info *info, int whichray, float distance) // probablenent suppr float distance
{
	int		y;
	float	wall_down;
	y = 0;
	wall_down = (info->screenHeight - distance) / 2;
	while (y < info->screenHeight)
	{
		while (y < wall_down) //plafond
		{
			mlx_pixel_put(info->s.mlx, info->s.win, whichray, y, 0x87ceff);
			y++;
		}
		while (y < (wall_down + distance)) //mur
		{
			mlx_pixel_put(info->s.mlx, info->s.win, whichray, y, 0xcd853f);
			y++;
		}
		mlx_pixel_put(info->s.mlx, info->s.win, whichray, y, 0x54ff9f);  //sol
		y++;
	}
}

int	main()
{
	t_info info;
	t_maptab tab;

	parsing(&tab);
	info.worldMap = tab.tab;
	fill_info(&info);
	info.s.mlx = mlx_init();
    info.s.win = mlx_new_window(info.s.mlx, info.screenWidth, info.screenHeight, "Cube3D");
	//s.img = mlx_new_image(s.mlx, info.screenWidth, info.screenHeight);
	rendering(&info);
	//	mlx_put_image_to_window(s.mlx, s.win, s.img, info.screenWidth, info.screenHeight);
	mlx_key_hook(info.s.win, ft_key_press, &info);
	// mlx_key_hook(s.win, ft_angle, &info);
//	mlx_loop_hook(s.mlx);
	//mlx_hook(s.win, 2, 1L<<0, ft_angle, &s);
//	mlx_hook(s.win, 3, 1L<<1, ft_angle, &s);
	mlx_hook(info.s.win, 2, 1L<<0, ft_close, &info.s); //fermer la fenetre, 0xffff);  //imprimer pixel
    mlx_loop(info.s.mlx);
}

void rendering (t_info *info)
{
	int whichray;
	float shortest_distance;
	float slice_hight;


	whichray = 0;
	while(whichray < info->screenWidth)
	{
		printf("ray = %d\n", whichray);
		update_info(info);
		p_on_plan(info, (float)whichray);
		ray(&info->ray, info->a, info->p_of_plan);
		test_x_axis(info);
		test_y_axis(info);
		shortest_distance = distance_to_wall(info);
		slice_hight = walls(info, shortest_distance, whichray);
		printf("distance %f\n", shortest_distance);
		printf("slice_hight %f\n", slice_hight);
		ft_display(info, whichray, slice_hight);
		whichray++;
		// printf("a.x = %f\n", info->a.x);
		// printf("a.y = %f\n", info->a.y);
	}
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
	
	n = 0;
	hit = 0;
	info->redflag[0] = 0;
	info->test_axis[n].x = (info->a.x < info->p_of_plan.x) ? info->next_axis[n] : info->next_axis[n] - info->blocksize;
	while (hit == 0)
	{
		find_y(&info->test_axis[n], info->ray.m, info->ray.n);
		// printf("test x = %f\n", info->test_axis[n].x);
		// printf("test y = %f\n", info->test_axis[n].y);
		if (map_bounderies(info, n) == 1)
			break;
		if((hit = hit_map(info, n) == 1))
		{
			// printf("hit = %d\n", hit);
			break;
		}
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
		{
			printf("hit = %d\n", hit);
			break;
		}
		printf("info->test_axis[1] = %f\n", info->test_axis[n].x);
		printf("info->test_axis[1] = %f\n", info->test_axis[n].y);
		info->test_axis[n].y += (info->a.y < info->p_of_plan.y) ? info->blocksize : - info->blocksize;
		printf("info->test_axis[1] = %f\n", info->test_axis[n].x);
		printf("info->test_axis[1] = %f\n", info->test_axis[n].y);
	}
}

int map_bounderies(t_info *info, int n)
{
	if ((int)info->test_axis[n].x < 0 || (int)info->test_axis[n].y < 0)
	{
		info->redflag[n] = 1;
		// printf("info->redflag[n] = %d\n", info->redflag[n]);
		return (1);
	}
	if ((int)info->test_axis[n].x >= (int)(mapHeight * info->blocksize) || (int)info->test_axis[n].y >= (int)(mapWidth * info->blocksize))
	{
		info->redflag[n] = 1;
		// printf("info->redflag[n] = %d\n", info->redflag[n]);
		return (1);
	}
	return (0);
}

float distance_to_wall(t_info *info)
{
	float distance[2];

	if (info->redflag[0] == 1)
	{
		// printf("--------------1--------------\n");
		// printf("distance[0] %f\n", distance[0]);
		// printf("distance[1] %f\n", distance_2_points(info->a, info->test_axis[1]));
		return (distance_2_points(info->a, info->test_axis[1]));
	}
	if (info->redflag[1] == 1)
	{
		// printf("--------------2--------------\n");
		// printf("distance[0] %f\n", distance[0]);
		// printf("distance[1] %f\n", distance[1]);
		return (distance_2_points(info->a, info->test_axis[0]));
	}
	printf("info->a = %f\n", info->a.x);
	printf("info->a = %f\n", info->a.y);
	printf("info->test_axis[0] = %f\n", info->test_axis[0].x);
	printf("info->test_axis[0] = %f\n", info->test_axis[0].y);
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
	// printf("map A = %d\n", (mapHeight - 1) - info->map[n].y);
	// printf("map B = %d\n", info->map[n].x);
	// printf("test x = %d\n", info->map[n].x);
	// printf("test y = %d\n", info->map[n].y);	
	if (info->map[n].x < 0 || info->map[n].y < 0) // y sais etre moins 1 dans le test peut etre x aussi
		return (1);
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
