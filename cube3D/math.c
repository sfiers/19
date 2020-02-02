#include "wolf.h"

float toa(float angle, float o)
{
	float a;

	a = o / tan((2 * (float)PI) / (360 / angle));

	return (a);
}

// int distance_to_previous_axis(int position, int blocksize)
// {
// 	return (position - ((floor(position / blocksize))*blocksize));
// }

int bloc_to_map(float position, float blocksize)
{
	return(floor((int)position / (int)blocksize));
} 