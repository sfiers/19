#include "wolf.h"
#include "minilibx/mlx.h"

int             ft_close(int keycode, mlx_ptr_t *s)
{
	if (keycode == 53)
    	mlx_destroy_window(s->mlx, s->win);
	return(0);
}

int             ft_moove(int keycode, t_info *info)
{
	if (keycode == 126) //fleche avant
    {
    	motion(info, FORWARD);
	}
	if (keycode == 125) //fleche arriere
	{
    	motion(info, BACKWARD);
	}
	printf("a.x = %f\n", info->a.x);
	return(0);
}

int             ft_angle(int keycode, t_info *info)
{
    int i;
    // 360 deg done in 2 seconds while button is pressed = 0,0055555555 sec per deg
    if (keycode == 123)
	{
    	(info->angle) -= 2; // motion(info, RIGHT); doit encore etre implémenté si nécessaire
	}
	if (keycode == 124)
	{
    	(info->angle) += 2; // motion(info, LEFT);
	}
	printf("keycode2 = %d\n", keycode);
	printf("info.angle = %f\n", info->angle);
	return(0);
}