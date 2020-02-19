#include "wolf.h"

// int	main()
// {
// 	t_info info;
// 	mlx_ptr_t s;
// 	t_maptab tab;
// 	int i;
// 	int whichray;
// 	double distance;
// 	double slice_hight;
	
// 	parsing(&tab);
// 	info.worldMap = tab.tab;
	
// 	fill_info(&info);
	
// 	//s.img = mlx_new_image(s.mlx, info.screenWidth, info.screenHeight);
// 	motion(&info, 1);
// 	// // // printf("motion \n");
// 	//	mlx_put_image_to_window(s.mlx, s.win, s.img, info.screenWidth, info.screenHeight);
// 	// mlx_key_hook(s.win, ft_moove, &info);
// // /	mlx_key_hook(s.win, ft_angle, &info);
// //	mlx_loop_hook(s.mlx);
// 	//mlx_hook(s.win, 2, 1L<<0, ft_angle, &s);
// //	mlx_hook(s.win, 3, 1L<<1, ft_angle, &s);

// }


/*
**function that handles everything related to the movement of the player
*/

void motion(t_info *info, int motion)
{
	if (motion == 1 || motion == -1)
		forward_backward(info, motion);
}

void forward_backward(t_info *info, int motion) // motion 1 forward -1 backward
{
	double displacement[2];

	displacement[0] = motion * cos(ft_deg2rad(info->angle)) * 10; // 10 is arbitrary, the bigger the less smooth
	displacement[1] = motion * sin(ft_deg2rad(info->angle)) * 10; // 10 is arbitrary, the bigger the less smooth

	if (allowed_motion(info, displacement))
	{
		info->a.x += round(displacement[0]);
		info->a.y += round(displacement[1]);
	}
}

int allowed_motion(t_info *info, double *displacement)
{
	t_p position_proposal;
	t_map map_check;

	position_proposal.x = info->a.x + displacement[0];
	position_proposal.y = info->a.y + displacement[1];

	map_check.x = bloc_to_map(position_proposal.x, info->blocksize);
	map_check.y = bloc_to_map(position_proposal.y, info->blocksize);

	if (inside_map(info, map_check))
	{
		if (avoid_wall(map_check, info))
		{
			return (1);
		}
	}
	return (0);
}

/*
**Checks if we the proposal of coordinates is inside the map
**Not mandatory if map is surrounded by walls
*/

int inside_map(t_info *info, t_map coordinates)
{
	if (coordinates.x >= 0 && coordinates.x < mapHeight)
	{	
		if ((coordinates.y >= 0 && coordinates.y < mapWidth))
			return (1);
	}
	return (0);
}

/*
**Checks if we don't move into a wall
**maybe other constraints will be added
*/

int avoid_wall(t_map coordinates, t_info *info)
{
	if (info->worldMap[(mapWidth - 1) - coordinates.y][coordinates.x] != 1) // 1 for Wall maybe there are other checks afterwards that need to be done
		return (1);
	return(0);
}
