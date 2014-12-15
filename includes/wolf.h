/*
** wolf.h for wolf in /home/telenc_r/rendu/wolf/includes
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 11:31:48 2012 telenc_r
** Last update Sun Jan 13 23:09:12 2013 telenc_r
*/

#ifndef WOLF_H_
# define WOLF_H_

#define WIDTH		1000
#define HEIGHT		800
#define P		1
#define D		0.5
#define SPEED		0.03
#define MY_PI		3.1415926535
#define RAD(a)		(a * MY_PI) / 180
#define MAX(a, b)	(a < b)? (a) : (b)
#define MIN(a, b)	(a < b)? (b) : (a)
#define	FLOOR		0x422307
#define SKY		0x77B5FE
#define PLAYER		0x798081
#define TOKEN		0x9E0E40
#define WALL		0x357AB7

typedef struct	s_keyboard
{
  int		up;
  int		down;
  int		left;
  int		right;
}		t_keyboard;

typedef struct	s_image
{
  void		*image;
  unsigned char		*data;
  int		bpp;
  int		size_line;
  int		endian;
}		t_image;

typedef struct	s_texture
{
  t_image	*wall_one;
  t_image	*wall_two;
  t_image	*wall_three;
  t_image	*wall_four;
  t_image	*load;
  t_image	*nb0;
  t_image	*nb1;
  t_image	*nb2;
  t_image	*nb3;
  t_image	*nb4;
  t_image	*nb5;
  t_image	*nb6;
  t_image	*nb7;
  t_image	*nb8;
  t_image	*nb9;
  t_image	*nbs;
  t_image	*win;
  t_image	*loose;
  t_image	*hand;
  t_image	*hand_left;
  t_image	*hand_tok;
  t_image	*hand_left_tok;
}		t_texture;

typedef struct	s_wall
{
  float		height_wall;
  float		x_shoot;
  float		y_shoot;
  int		type_shoot;
  t_image	*texture;
}		t_wall;

typedef struct	s_f_point
{
  float		x;
  float		y;
}		t_f_point;

typedef struct	s_i_point
{
  int		x;
  int		y;
}		t_i_point;

typedef struct	s_map
{
  int		skin;
  int		visible;
  int		size;
  int		is_seen;
}		t_map;

typedef struct	s_obj
{
  t_f_point	*pos;
  t_image	*texture;
  struct s_obj	*next;
}		t_obj;

typedef	struct	s_player
{
  int		max_tok;
  int		nb_tok;
  t_f_point	*pos_player;
  int		deg_player;
  float		cos_player;
  float		sin_player;
  int		num_game;
}		t_player;

typedef struct	s_wolf
{
  t_map		**map;
  int		screen;
  int		size_line_map;
  int		size_map;
  void		*mlx;
  void		*win;
  void		*img;
  int		bpp;
  int		size_line;
  int		endian;
  float		k;
  unsigned char		*data;
  t_keyboard	*keyboard;
  t_texture	*texture;
  t_obj		*object;
  t_player	*play;
  int		fps;
}		t_wolf;

char		**my_split_str(char *, char);
char		*get_next_line(const int);
char		*my_strcat(char *, char *, int);
char		*my_nbr_to_char(int);
void		my_putstr(char *);
void		my_putchar(char);
void		*my_malloc(int);
void		my_put_pixel_img(t_wolf *, int, int, unsigned long);
void		my_put_pixel_img_wall(t_wolf *, int, int, t_wall *);
void		init_pos_player(t_wolf *);
void		init_key_board(t_wolf *);
void		init_fenetre(t_wolf *);
void		draw_line(t_wolf *, t_i_point *, t_i_point *, unsigned long);
void		draw_line_wall(t_wolf *, t_i_point *, t_i_point *, t_wall *);
void		draw_floor(t_wolf *);
void		draw_sky(t_wolf *);
void		draw_wall(t_wolf *);
void		draw_object(t_wolf *, t_obj *);
void		error_file();
void		error_minilibx();
void		error_texture();
void		error_write();
void		error_malloc();
void		verif(char *);
void		change_pos_up(t_wolf *);
void		change_pos_down(t_wolf *);
void		init_image(t_wolf *);
void		quit_wolf(t_wolf *);
void		define_wall(t_wall *, t_f_point, t_wolf *, int);
void		my_putmap(t_map **, t_wolf *);
void		draw_object(t_wolf *, t_obj *);
void		rotate(t_f_point *, int);
void		change_deg(t_wolf *, int);
int		mouse_hook(int, int, int, t_wolf *);
int		cas_un(t_wolf *, t_i_point *, t_i_point *, unsigned long);
int		cas_deux(t_wolf *, t_i_point *, t_i_point *, unsigned long);
int		key_code(int, t_wolf *);
int		key_release(int, t_wolf *);
int		loop_hook(t_wolf *);
int		is_wall(int, int, t_wolf *, int);
int		number_oc_char(char *, char);
int		abs(int);
int		my_put_img_to_img(t_image *, t_wolf *, t_i_point *, float);
int		my_strlen(char *);
int		my_strlen_double_char(char **);
int		my_getnbr(char *);
float		get_norme(t_f_point *);
t_f_point	*get_vector_directory(t_wolf *, float);
t_obj		*remove_object(t_obj *, t_obj *);
t_image		*create_texture(char *, t_wolf *);
t_image		*get_img(t_wolf *, char);
t_wall		*get_wall(t_f_point *, t_wolf *, int);
t_obj		*add_struct(t_obj *, float, float, t_image *);
t_map		**create_map(char *, t_wolf *);

#endif /* !WOLF_H_ */
