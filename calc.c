/*
** calc.c for calc in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  2 16:30:42 2013 telenc_r
** Last update Sun Jan 13 14:51:05 2013 telenc_r
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"wolf.h"

int	is_wall(int x, int y, t_wolf *wolf, int visible)
{
  if (x >= 0 && x < wolf->size_line_map && y >= 0 && y < wolf->size_map - 1)
    if (wolf->map[x + (y * wolf->size_line_map)]->skin > 0)
      if (wolf->map[x + (y * wolf->size_line_map)]->visible == visible)
	return (1);
  return (0);
}

t_f_point	*get_vector_directory(t_wolf *wolf, float x)
{
  t_f_point	*result;
  float		sauv_x;
  float		sauv_y;

  result = my_malloc(sizeof(t_f_point));
  result->x = D;
  result->y = (P * ((WIDTH/2) - x)) / WIDTH;
  sauv_x = result->x;
  sauv_y = result->y;
  result->x = (sauv_x * wolf->play->cos_player) - (sauv_y *
						   wolf->play->sin_player);
  result->y = (sauv_x * wolf->play->sin_player) + (sauv_y *
						   wolf->play->cos_player);
  return (result);
}

t_wall		*get_wall_y(t_f_point *vector_directory,
			    t_wolf *wolf, int visible)
{
  t_wall	*result_y;
  float		result;
  float		sauv_result;
  t_f_point	point;

  result_y = my_malloc(sizeof(t_wall));
  sauv_result = 1000;
  point.y = 0.0;
  while (point.y <= wolf->size_map)
    {
      result = (point.y - wolf->play->pos_player->y) / vector_directory->y;
      point.x = wolf->play->pos_player->x + (result * vector_directory->x);
      if (is_wall(point.x, point.y, wolf, visible) ||
	  is_wall(point.x, (point.y - 1), wolf, visible))
	if (result <= sauv_result && result > 0)
	  {
	    define_wall(result_y, point, wolf, visible);
	    result_y->type_shoot = 2;
	    sauv_result = result;
	  }
      point.y += 1;
    }
  result_y->height_wall = sauv_result;
  return (result_y);
}

t_wall		*get_wall_x(t_f_point *vector_directory, t_wolf *wolf, int vis)
{
  t_wall	*result_x;
  float		result;
  float		sauv_result;
  t_f_point	p;

  result_x = my_malloc(sizeof(t_wall));
  sauv_result = 1000;
  p.x = 0.0;
  while (p.x < wolf->size_line_map)
    {
      result = (p.x - wolf->play->pos_player->x) / vector_directory->x;
      p.y = wolf->play->pos_player->y + (result * vector_directory->y);
      if (is_wall(p.x, p.y, wolf, vis) || is_wall(p.x - 1, p.y, wolf, vis))
	if (result < sauv_result && result > 0)
	  {
	    define_wall(result_x, p, wolf, vis);
	    result_x->type_shoot = 1;
	    sauv_result = result;
	  }
      p.x += 1;
    }
  result_x->height_wall = sauv_result;
  return (result_x);
}

t_wall		*get_wall(t_f_point *vector_directory, t_wolf *wolf, int visible)
{
  t_wall	*result_y;
  t_wall	*result_x;

  result_y = get_wall_y(vector_directory, wolf, visible);
  result_x = get_wall_x(vector_directory, wolf, visible);
  if (result_y->height_wall < result_x->height_wall)
    if (result_y->height_wall > 0)
      {
	free(result_x);
	return (result_y);
      }
  free(result_y);
  return (result_x);
}
