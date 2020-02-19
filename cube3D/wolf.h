#ifndef WOLF_H 
# define WOLF_H
// a.x = 750.951965
// a.y = 265.356750
// angle = 60.000000
// a.x = 387.368622
// a.y = 1325.184814
// angle = 180.000000

#define mapWidth 24
#define mapHeight 24

// double worldMap[mapWidth][mapHeight]=
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
	double x;
	double y;
	double z;
}				    t_p;

typedef struct      s_map
{
	int x;
	int y;
	int z;
}				    t_map;

typedef struct		s_ray
{
	double m;
	double n;
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
	double blocksize;
	double angle;
	int		screenWidth;
	int		screenHeight;
	double pov;
	t_p	a;
	t_p	b;
	t_p	c;
	t_p	d;
	t_p	dir;
	t_p plan;
	t_p p_of_plan;
	double ad;
	double bd;
	double bad;
	t_ray ray;
	double next_axis[2];
	t_map map[2]; // x axis = 0 and y axis 1
	t_p test_axis[2];
	int redflag[2];
	t_mlx_ptr s;
}				    t_info;

typedef struct      s_error
{
	int		ret;
	char	*msg;
}					t_error;

typedef struct      s_maptab
{
	int		fd;
	char	*line;
	//int		*newline;
	int		counter;
	int 	len_max;
	//int		check_len;
	int 	letter;
	char 	*map_str1;
	char	*map_str2;
	int		lines_nb;
	int		**tab;
	int		i;
	//int		**len_tab;
	//int		lastcube;
	int		ret;
	//char	*error;
	//int		ret2;
}					t_maptab;



/*
** --------------------------------- Define ------------------------------------
*/

// #define PI 3.14159265358979323846264338327950288419716939937510
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
int hit_map(t_info *info, int n);
double distance_to_wall(t_info *info);
void test_x_axis(t_info *info);
void test_y_axis(t_info *info);
void p_on_plan(t_info *info, double whichray);

/*
** --------------------------- Parsing Functions -------------------------------
*/

void fill_info(t_info *info);
int	parsing(t_maptab *tab, t_error *error);
int			first_string(t_maptab *tab, t_error *error);
void		put_error(t_error *error);
void	ft_putstr1(char *s); // doublon
char		*ft_join_lines(char *temp, char *line, int counter);
char	*ft_strdup1(char *s1); // doublon
int	check_vside(t_error *error, char **line, int i, int *letter);
int		error_ret(t_error *error);
int		cleanline(t_maptab *tab, t_error *error, char **line, char **newline);
int		ft_strlen1(char *s); // doublon
int		ft_strlen2(char *s);
int		len_row(t_maptab *tab);
int			second_string(t_maptab *tab, t_error *error);
int		lastcheck_closing(t_maptab *tab, t_error *error);
int 	verify_wall(t_maptab *tab, t_error *error, int x, int y);
/*
** ----------------------------- Error Handling- -------------------------------
*/

int map_bounderies(t_info *info, int n);

/*
** ------------------------------ conversions ----------------------------------
*/

int bloc_to_map(double position, double blocksize);


/*
** ----------------------------- Maths Functions -------------------------------
*/

double distance_2_points(t_p a, t_p b);
void ray(t_ray *ray, t_p a, t_p b);
double ft_deg2rad(double degree);
void find_y(t_p *a, double m, double n);
void find_x(t_p *a, double m, double n);
double toa(double angle, double o);

/*
** ---------------------- Strings & Chars Functions ----------------------------
*/

// size_t		ft_strlen(constchar *str); // fonction pour les string

/*
** ------------------------------- Walls ---------------------------------------
*/

double walls(t_info *info, double distance, int whichray);
double fishbowl(t_info *info, double distorted_distance, int whichray);
double projected_slice_hight(t_info *info, double distance);
void	ft_display(t_info *info, int whichray, double distance);

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
int allowed_motion(t_info *info, double *displacement);
int avoid_wall(t_map coordinates, t_info *info);
int inside_map(t_info *info, t_map coordinates);
int	ft_key_press(int keycode, t_info *info);

/*
** --------------------------- Rendering --------------------------------------
*/

void rendering (t_info *info);
void update_info(t_info *info);


#endif