#include "wolf.h" 

// typedef struct      s_droite
// {
// 	double a;
// 	double b;
// 	double c;
// }					t_droite;

// typedef struct      s_sprites
// {
// 	double distance[nbsprite];
// 	int nbsprite;
// 	double x[nbsprite];
// 	double y[nbsprite];
// 	double seensprites[whichray][nbsprites];
// 	t_p spriteplandir;
// 	double startdrawx[nbsprite];
// 	double startdrawy[nbsprite];
// 	int startray;
// 	double ab[nbsprites];
// 	double disttworay[nbsprites];
// 	t_ray firstray;
// 	t_ray lastray;
// 	t_ray spriteray;
// 	t_ray xaxis;
// 	t_droite droitetemp;
// 	t_droite droitetemp2;
// 	t_p pointtemp;
// 	t_p temp2;
// 	// float rayseekm;
// }				    t_sprites;

// t_sprites barrel;

// void findray(t_sprites *barrel, t_info *info, int i)
// {
// 	double distance;
// 	double distance2;
// 	int i;

// 	i = 0;
// 	barrel->pointtemp.x = barrel->startdrawx[i];
// 	barrel->pointtemp.y = barrel->startdrawy[i];
// 	While (i < info->whichray)
// 	{
// 		// y = mx + n=> Ax + By + C = 0
// 		droitetemp.a = barrel->a[whichray]; // m
// 		droitetemp.b = barrel->b[whichray]; // -1
// 		droitetemp.c = barrel->c[whichray]; // n
// 		droitetemp2.a = barrel->a[whichray + 1];
// 		droitetemp2.b = barrel->b[whichray + 1];
// 		droitetemp2.c = barrel->c[whichray + 1];
// 		distance = ft_distancepointdroite(barrel->temp, barrel->droitetemp);
// 		distance2 = ft_distancepointdroite(barrel->temp, barrel->droitetemp2);
// 		if(distance < distance2)
// 			break;
// 	}
// 	barrel->startray = i - 1;
// 	return;
// }

// void handlesprites(t_sprites *barrel, t_info *info)
// {
// 	int i;

// 	i = 0;
// 	coordinatesofbarrel(barrel, info); // coordonnees x et y de chaque sprite via la map
// 	distance_2_sprite(barrel, info); // distance entre le centre de chaque sprite et la joueur
// 	ft_sort_sprite(barrel, info); // tri les distances du + loin au + proche 
// 	while (i < info->nbsprite)
// 	{	
// 		initialise(barrel, info, i);
// 		seekdrawstart(barrel, info, i);
// 		findray(barrel, info, i);
// 	}
// }

void handlesprites(t_sprites *barrel, t_info *info)
{
	int i;

	i = 0;
	coordinatesofbarrel(barrel, info); // coordonnees x et y de chaque sprite via la map
	distance_2_sprite(barrel, info); // distance entre le centre de chaque sprite et la joueur
	// ft_sort_sprite(barrel, info); // tri les distances du + loin au + proche 
	// while (i < info->nbsprite)
	// {	
	// 	initialise(barrel, info, i);
	// 	seekdrawstart(barrel, info, i);
	// 	findray(barrel, info, i);
	// }
}

// void initialise(t_sprites *barrel, t_info *info, int i)
// {
// 	t_p spritecoordinates;
// 	double spriteangle;

// 	spritecoordinates.x = barrel->x[i];
// 	spritecoordinates.y = barrel->y[i];
// 	ray(barrel->spriteray, info->a, spritecoordinates);  // calcule droite allant du centre du sprite au joueur;
// 	// ci dessous on calcule l angle aigu entre 2 droite (x axis et spriteray)
// 	spriteangle = ft_rad2deg(atan(fabs(barrel->spriteray.m))); // car equation de la droite x axis est y = 0 et la formule tan(alpha) = abs ((m2-m1)/(1 +(m2*m1)))
// 	// le spriteangle doit etre proche du vrai angle 
// 	if(barrel->spriteray.m > 0)
// 	{
// 		if(barrel->y[i] < info->a.y)
// 			spriteangle += 180	
// 	}
// 	else
// 	{
// 		spriteangle = 180 - spriteangle;
// 		if(barrel->y[i] < info->a.y)
// 			spriteangle += 180;	
// 	}
// 	barrel->spriteplandir.x = round(cos(ft_deg2rad(spriteangle + 90)) * info->blocksize/2);
// 	barrel->spriteplandir.y = round(sin(ft_deg2rad(spriteangle + 90)) * info->blocksize/2);
// }

// void seekdrawstart(t_spites *barrel, t_info *info, int i)
// {
// 	barrel->drawstartx[info->nbsprite] = barrel->x[info->nbsprite] + barrel->spriteplandir.x
// 	barrel->drawstarty[info->nbsprite] = barrel->y[info->nbsprite] + barrel->spriteplandir.y
// }

void distance_2_sprite(t_sprites *barrel, t_info *info)
{
	int i;

	i = 0;
	while (i < info->nbsprite)
	{
		barrel->distance[i] = sqrt(pow(barrel->x[i] - info->a.x, 2) + pow(barrel->y[i] - info->a.y, 2));
		// printf("barrel->x[%d] = %f\n", i , barrel->x[i]);
		// printf("barrel->y[%d] = %f\n", i , barrel->y[i]);
		// printf("distance[%d] = %f\n", i, barrel->distance[i]);
		i++;
	}
}

// void ft_sort_sprites(t_sprites *barrel, t_info *info)
// {
// 	int	count;
// 	int	i;
// 	double tmp[3];
	
// 	count = 0;
// 	while (count < info->nbsprite)
// 	{
// 		i = 0;
// 		while (i < (info->nbsprite) - 1))
// 		{
// 			if (barrel->distance[i] > barrel->distance[i + 1])
// 			{
// 				tmp[0] = barrel->distance[i];
// 				tmp[1] = barrel->x[i];
// 				tmp[2] = barrel->y[i];
// 				barrel->distance[i] = barrel->distance[i + 1];
// 				barrel->x[i] = barrel->x[i + 1];
// 				barrel->y[i] = barrel->y[i + 1];
// 				barrel->distance[i + 1] = tmp[0]
// 				barrel->x[i + 1] = tmp[1]
// 				barrel->y[i + 1] = tmp[2]
// 			}
// 			i++;
// 		}
// 		count++;
// 	}
// }

void coordinatesofbarrel(t_sprites *barrel, t_info *info)
{
	int i;
	int j;
	int n;

	i = 0;  // lignes
	j = 0;  // colonnes
	n = 0;
	while (i < mapHeight)
	{
		j = 0;
		while (j < mapWidth)
		{
			//printf("info->worldMap[%d][%d] = %d\n", i, j, info->worldMap[i][j]);
			if (info->worldMap[i][j] == 2) // si un sprite c'est 2
			{
				barrel->x[n] = j * 64 + 32; // a verifier pour voir si c'est bon 
				barrel->y[n] = (mapHeight - 1 - i) * 64 + 32; // a verifier pour voir si c'est bon
				n++;
				//printf("barrel.x = %f et barrel.y = %f\n", barrel->x[n], barrel->y[n]);
			}
			j++;
			//printf("j = %d\n", j);
		}
		i++;
		//printf("i = %d\n", i);
	}
}
