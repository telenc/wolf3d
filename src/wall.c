/*
** wall.c for wall in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  2 15:40:24 2013 telenc_r
** Last update Sun Jan 13 23:03:13 2013 telenc_r
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	"wolf.h"

void	define_wall(t_wall *wall, t_f_point p, t_wolf *wolf, int visible)
{
  int	text;

  wall->x_shoot = p.x;
  wall->y_shoot = p.y;
  if (is_wall((int)p.x , (int)p.y, wolf, visible))
    text = wolf->map[(int)p.x + ((int)p.y * wolf->size_line_map)]->skin;
  else if (p.x - (int)p.x == 0)
    text = wolf->map[(int)(p.x - 1) + ((int)p.y * wolf->size_line_map)]->skin;
  else
    text = wolf->map[(int)p.x + ((int)(p.y - 1) * wolf->size_line_map)]->skin;
  if (text == 1)
    wall->texture = wolf->texture->wall_one;
  else if (text == 2)
    wall->texture = wolf->texture->wall_two;
  else if (text == 3)
    wall->texture = wolf->texture->wall_three;
  else
    wall->texture = wolf->texture->wall_four;
}

int		display_object(t_wolf *wolf, t_i_point *p1, t_obj *tmp)
{
  t_f_point	*vector_directory;
  float		k;

  if (p1->x < 0)
    return (0);
  vector_directory = get_vector_directory(wolf, p1->x);
  k = ((tmp->pos->x - wolf->play->pos_player->x) / vector_directory->x);
  if ((int)k == 0)
    k = 1.5;
  my_put_img_to_img(wolf->texture->wall_one, wolf, p1, k);
}

void		draw_wall(t_wolf *wolf)
{
  t_f_point	*vector_directory;
  float		x;
  t_wall	*wall;
  t_i_point	p1;
  t_i_point	p2;
  int		pos;

  x = 0.0;
  while (x < WIDTH)
    {
      vector_directory = get_vector_directory(wolf, x);
      wall = get_wall(vector_directory, wolf, 1);
      wall->height_wall = HEIGHT / (2 * wall->height_wall);
      p1.x = x;
      p1.y = (HEIGHT/2) - (int)(wall->height_wall);
      p2.x = x;
      p2.y = (HEIGHT/2) + (int)(wall->height_wall);
      draw_line_wall(wolf, &p1, &p2, wall);
      free(wall);
      x++;
    }
}

void		draw_floor(t_wolf *wolf)
{
  int		y;
  t_i_point	p1;
  t_i_point	p2;
  unsigned long	color_floor;

  color_floor = mlx_get_color_value(wolf->mlx, FLOOR);
  y = HEIGHT / 2;
  while (y < HEIGHT)
    {
      p1.x = 0;
      p1.y = y;
      p2.x = WIDTH;
      p2.y = y;
      draw_line(wolf, &p1, &p2, color_floor);
      y++;
    }
}

void		draw_sky(t_wolf *wolf)
{
  int		y;
  t_i_point	p1;
  t_i_point	p2;
  unsigned long	color_floor;

  color_floor = mlx_get_color_value(wolf->mlx, SKY);
  y = 0;
  while (y < HEIGHT / 2)
    {
      p1.x = 0;
      p1.y = y;
      p2.x = WIDTH;
      p2.y = y;
      draw_line(wolf, &p1, &p2, color_floor);
      y++;
    }
}
