#include "wolf.h"

/*
**function that handles everything related to the walls once we have
**the correct distance to a wall
*/

float walls(t_info *info, float distance, int whichray)
{
	float corrected_distance;
	float slice_hight;

	corrected_distance = fishbowl(info, distance, whichray); // il faut appliquer cette formule pour tout angle ou juste pour les angle droit??
	// printf("---------------------------------------------------------corrected_distance %f\n", corrected_distance);
	slice_hight = projected_slice_hight(info, corrected_distance);
	return (slice_hight);
}


/*
**https://www.permadi.com/tutorial/raycast/rayc8.html
**pour afficher un mur droit quand on est face a un mur
*/

float fishbowl(t_info *info, float distorted_distance, int whichray)
{
	float angle_offset;
	float corrected_distance;

	angle_offset = info->pov / info->screenWidth;
	// printf("angle_offset = %f\n", angle_offset);
	if (whichray < (int)(info->screenWidth / 2))
		corrected_distance = distorted_distance * cos(ft_deg2rad((info->pov / 2) - (whichray * angle_offset)));
	else
		corrected_distance = distorted_distance * cos(ft_deg2rad(((whichray - (info->screenWidth / 2)) * angle_offset)));
	return (corrected_distance);
}

/*
**https://www.permadi.com/tutorial/raycast/rayc9.html
**adapter la taille du mur par rapport a la distance au plan et non la réelle distance
*/

float projected_slice_hight(t_info *info, float distance)
{
	float projected_slice_hight;

	projected_slice_hight = (info->blocksize / distance) * info->ad;
	return(projected_slice_hight);
}