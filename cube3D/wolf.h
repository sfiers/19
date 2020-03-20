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
#include "./libft/libft.h"
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

typedef struct	s_tex_no
{
	void *ptr;
	int *img;
	int *data;
	int size;
	int bpp;
	int a; 
}				t_tex_no;

typedef struct	s_tex_we
{
	void *ptr;
	int *img;
	int *data;
	int size;
	int bpp;
	int a; 
}				t_tex_we;

typedef struct	s_tex_ea
{
	void *ptr;
	int *img;
	int *data;
	int size;
	int bpp;
	int a; 
}				t_tex_ea;

typedef struct	s_tex_so
{
	void *ptr;
	int *img;
	int *data;
	int size;
	int bpp;
	int a; 
}				t_tex_so;

typedef struct	s_mlx_ptr
{
	void *win;
	void *mlx;
	void *ptr;
	int *img;
	int *data;
	int size;
	int bpp;
	int a; 
}				t_mlx_ptr; 

// typedef struct s_rgb
// {
// 	char red;
// 	char green;
// 	char blue;
// 	char opacity;
// }				t_rgb;

typedef struct      s_info
{
	int **worldMap;
	int sptab[mapHeight*mapWidth*2];
	double blocksize;
	double angle;
	int wallx; // retirer >???
	int		screenWidth;
	int		screenHeight;
	int		trgb_ceiling;
	int		trgb_floor;
	double tex_y; //*********new
	double tex_x; //*********new
	double pov;
	int side; //*********new
	int nesw;
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
	t_mlx_ptr no;
	t_mlx_ptr so;
	t_mlx_ptr we;
	t_mlx_ptr ea;
	t_mlx_ptr sp;
	int i;
	int wall[2];
	int spflag;
	double spdistance;
	double spratio;
	double sp_x;
	double sp_y;
	double temp_y;
	int nbsprite;

//	int wall[2];
	// t_rgb ceiling;
	// t_rgb wall;
	// t_rgb floor;
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
	t_error error;
}					t_maptab;

typedef struct      s_element
{
	char *line;
	int counter;
	char *texture_we;
	char *texture_sprite;
	char *texture_no;
	char *texture_ea;
	char *texture_so;
	int fd;
	int ret;
	int i;
	char *msg;
	int flag;
	int t;
	int r;
	int g;
	int b;
	char *t_hex;
	char *r_hex;
	char *g_hex;
	char *b_hex;
	// int	t_hex;
	// int	r_hex;
	// int	g_hex;
	// int	b_hex;
	char *trgb;
	int trgb_floor;
	int trgb_ceiling;
	int comma;
}					t_element;

typedef struct      s_droite
{
	double a;
	double b;
	double c;
}					t_droite;

typedef struct      s_sprites
{
	//int nbsprite;
	double distance[mapWidth*mapHeight];
	double x[mapWidth*mapHeight];
	double y[mapWidth*mapHeight];
	//double seensprites[whichray][mapWidth*mapHeight];
	t_p spriteplandir;
	double startdrawx[mapWidth*mapHeight];
	double startdrawy[mapWidth*mapHeight];
	int startray;
	double ab[mapWidth*mapHeight];
	double disttworay[mapWidth*mapHeight];
	t_ray firstray;
	t_ray lastray;
	t_ray spriteray;
	t_ray xaxis;
	t_droite droitetemp;
	t_droite droitetemp2;
	t_p pointtemp;
	t_p temp2;
	// float rayseekm;
}				    t_sprites;

typedef struct	mlx_ptr_s
{
	void *win;
	void *mlx;
	int *img;
}				mlx_ptr_t; // je crois que la norme nous force a t_mlx_ptr

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
int hit_map(t_info *info, int n);
double distance_to_wall(t_info *info);
void test_x_axis(t_info *info);
void test_y_axis(t_info *info);
void p_on_plan(t_info *info, double whichray);
void sprite(t_info *info, int n);

/*
** --------------------------- Parsing Functions -------------------------------
*/

/*
**  MAP ----------------
*/

void fill_info(t_info *info);
int	parsing(t_maptab *tab, t_info *info);
int			first_string(t_maptab *tab, t_info *info);
void		put_error(t_error *error);
void	ft_putstr1(char *s); // doublon
char		*ft_join_lines(char *temp, char *line, int counter);
char	*ft_strdup1(char *s1); // doublon
int	check_vside(t_maptab *tab, t_info *info, char **line, int i);
int		error_ret(t_error *error);
int		cleanline(t_maptab *tab, t_info *info, char **line, char **newline);
int		ft_strlen1(char *s); // doublon
int		ft_strlen2(char *s);
int		len_row(t_maptab *tab);
int			second_string(t_maptab *tab);
int		lastcheck_closing(t_maptab *tab, t_error *error);
int 	verify_wall(t_maptab *tab, int x, int y);

/*
**  ELEMENTS ----------------
*/

int if_digit(t_element *elem);
int create_trgb(t_element *elem, t_info *info, long int trgb);
int read_elem(t_element *elem, t_info *info);
int	parsing2(t_element *elem, t_info *info);
int texture(t_element *elem, t_info *info, char *path);
int color(t_element *elem, int trgb);
int resolution(t_element *elem, t_info *info);
int error_ret1(t_element *elem);
char	*ft_strdup1(char *s1);
int		ft_strlen1(char *s);
void		put_error1(t_element *elem);
int is_digit(char c);
void init_elem(t_element *elem);


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
double ft_rad2deg(double rad);
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
void put_texture(t_info *info);
void nesw(t_info *info);


/*
** ------------------------------- Sprites -------------------------------------
*/

void handlesprites(t_sprites *barrel, t_info *info);
void coordinatesofbarrel(t_sprites *barrel, t_info *info);
void distance_2_sprite(t_sprites *barrel, t_info *info);
void ft_sort_sprites(t_sprites *barrel, t_info *info);
void initialise(t_sprites *barrel, t_info *info, int i);
void seekdrawstart(t_sprites *barrel, t_info *info, int i);
void findray(t_sprites *barrel, t_info *info, int i);


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
int	ft_key_press(int keycode, t_info *info, t_sprites *barrel);

/*
** --------------------------- Rendering --------------------------------------
*/

void rendering(t_info *info, t_sprites *barrel);
void update_info(t_info *info);


#endif