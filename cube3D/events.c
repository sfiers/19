#include "wolf.h"
#include "minilibx/mlx.h"

int             ft_close(int keycode, t_mlx_ptr *s)
{
	if (keycode == 53)
    	mlx_destroy_window(s->mlx, s->win);
	return(0);
}

int	ft_key_press(int keycode, t_info *info, t_sprites *barrel)
{
	if (keycode == 125 || keycode == 126)
		ft_moove(keycode, info);
	if (keycode == 123 || keycode == 124)
		ft_angle(keycode, info);
	if (keycode == 53)
		exit(0);
    	// mlx_destroy_window(s->mlx, s->win);
	rendering(info, barrel);
	// // // printf("a.x = %f\n", info->a.x);
	// // // printf("a.y = %f\n", info->a.y);
	// // // printf("angle = %f\n", info->angle);
	return 0;
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
	return(0);
}

int             ft_angle(int keycode, t_info *info)
{
    int i;
    // 360 deg done in 2 seconds while button is pressed = 0,0055555555 sec per deg
    if (keycode == 123)
	{
    	(info->angle) += 5; // motion(info, RIGHT); doit encore etre implémenté si nécessaire
	}
	if (keycode == 124)
	{
    	(info->angle) -= 5; // motion(info, LEFT);
	}
	// // // printf("keycode2 = %d\n", keycode);
	// // // printf("info.angle = %f\n", info->angle);
	return(0);
}
