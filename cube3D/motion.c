#include "wolf.h"

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
	float displacement[2];

	
	displacement[0] = motion * cos(info->angle) * 10; // 10 is arbitrary, the bigger the less smooth
	displacement[1] = motion * sin(info->angle) * 10; // 10 is arbitrary, the bigger the less smooth

	if (allowed_motion(info, displacement))
	{
		info->a.x += displacement[0];
		info->a.y += displacement[1];
	}
}

int allowed_motion(t_info *info, float *displacement)
{
	t_p position_proposal;
	t_map map_check;

	position_proposal.x = info->a.x + displacement[0];
	position_proposal.y = info->a.y + displacement[1];

	map_check.x = bloc_to_map(position_proposal.x, info->blocksize);
	map_check.y = bloc_to_map(position_proposal.y, info->blocksize);

	if (inside_map(info, map_check))
	{
		if (avoid_wall(map_check, &info->worldMap))
			return (1);
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
		return(0);
	}
	else 
		return (0);
}

/*
**Checks if we don't move into a wall
**maybe other constraints will be added
*/

int avoid_wall(t_map coordinates, int ***worldMap)
{
	if (*worldMap[(mapWidth - 1) - coordinates.y][coordinates.x] == 1) // 1 for Wall maybe there are other checks afterwards that need to be done
		return (1);
	return(0);
}
