#ifndef WOLF_H 
# define WOLF_H

#define mapWidth 24
#define mapHeight 24

// float worldMap[mapWidth][mapHeight]=
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
//   {1,1,1,1,1,1,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,1,4,4,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}, // 20
//   {1,0,5,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,1,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  // 23 
// };

/*
** -------------------------- External Headers ---------------------------------
*/

#include "./minilibx/mlx.h"
#include "./GNL/get_next_line.h"
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
** ------------------------- Structure Definitions -----------------------------
*/

typedef struct      s_p
{
	float x;
	float y;
	float z;
}				    t_p;

typedef struct      s_map
{
	int x;
	int y;
	int z;
}				    t_map;

typedef struct		s_ray
{
	float m;
	float n;
}					t_ray;

typedef struct	s_mlx_ptr
{
	void *win;
	void *mlx;
	int *img;
	int *data;
	int size;
	int bpp;
	int a;
}				t_mlx_ptr; 

typedef struct      s_info
{
	int **worldMap;
	float blocksize;
	float angle;
	int		screenWidth;
	int		screenHeight;
	float pov;
	t_p	a;
	t_p	b;
	t_p	c;
	t_p	d;
	t_p	dir;
	t_p plan;
	t_p p_of_plan;
	float ad;
	float bd;
	float bad;
	t_ray ray;
	float next_axis[2];
	t_map map[2]; // x axis = 0 and y axis 1
	t_p test_axis[2];
	int redflag[2];
	t_mlx_ptr s;
}				    t_info;

typedef struct      s_maptab
{
	int		fd;
	char	*line;
	int		ret;
	int		counter;
	int 	len;
	int		check_len;
	int 	letter;
	char 	*map_str;
	int		lines_nb;
	int		**tab;
	int		i;
}					t_maptab;



/*
** --------------------------------- Define ------------------------------------
*/

#define PI 3.14159265358979323846264338327950288419716939937510
#define FORWARD 1
#define BACKWARD -1
#define LEFT 1
#define RIGHT -1 

/*
** -----------------------------------------------------------------------------
** ------------------------------- Sources -------------------------------------
** -----------------------------------------------------------------------------
*/

void print(t_info *info); // delete this crap
float hit_map(t_info *info, int n);
float distance_to_wall(t_info *info);
void test_x_axis(t_info *info);
void test_y_axis(t_info *info);
void p_on_plan(t_info *info, float whichray);

/*
** --------------------------- Parsing Functions -------------------------------
*/

void fill_info(t_info *info);
void	filling_tab(int lines_nb, int len, int ***tab, char *map_str);
int		ft_lines_number(char *map_str);
char	*ft_join_lines(char *temp, char *line, int len, int counter);
int		check_hside(char *s, int len); // les check pour les error dans error handling
int		check_vside(char **line, int len, int *letter);
int		start(t_maptab *tab);
int		parsing(t_maptab *tab);

/*
** ----------------------------- Error Handling- -------------------------------
*/

int map_bounderies(t_info *info, int n);

/*
** ------------------------------ conversions ----------------------------------
*/

int bloc_to_map(float position, float blocksize);


/*
** ----------------------------- Maths Functions -------------------------------
*/

float distance_2_points(t_p a, t_p b);
void ray(t_ray *ray, t_p a, t_p b);
float ft_deg2rad(float degree);
void find_y(t_p *a, float m, float n);
void find_x(t_p *a, float m, float n);
float toa(float angle, float o);

/*
** ---------------------- Strings & Chars Functions ----------------------------
*/

// size_t		ft_strlen(constchar *str); // fonction pour les string

/*
** ------------------------------- Walls ---------------------------------------
*/

float walls(t_info *info, float distance, int whichray);
float fishbowl(t_info *info, float distorted_distance, int whichray);
float projected_slice_hight(t_info *info, float distance);
void	ft_display(t_info *info, int whichray, float distance);

/*
** --------------------------- Key Events --------------------------------------
*/

int ft_close(int keycode, t_mlx_ptr *s); // fermer la fenetre
int ft_angle(int keycode, t_info *info);
int ft_moove(int keycode, t_info *info);

/*
** ------------------------------ Motion --------------------------------------
*/

void motion(t_info *info, int motion);
void forward_backward(t_info *info, int motion);
int allowed_motion(t_info *info, float *displacement);
int avoid_wall(t_map coordinates, t_info *info);
int inside_map(t_info *info, t_map coordinates);
int	ft_key_press(int keycode, t_info *info);

/*
** --------------------------- Rendering --------------------------------------
*/

void rendering (t_info *info);
void update_info(t_info *info);


#endif