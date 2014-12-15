/*
** object.c for object in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  9 16:23:04 2013 telenc_r
** Last update Sun Jan 13 23:01:00 2013 telenc_r
*/

#include	<stdlib.h>
#include	<math.h>
#include	"wolf.h"

void		draw_object(t_wolf *wolf, t_obj *tmp)
{
  float		coss;
  float		size_op;
  t_f_point	*vector_directory;
  t_f_point	*v_obj;
  t_i_point	*p1;

  p1 = my_malloc(sizeof(t_i_point));
  v_obj = my_malloc(sizeof(t_f_point));
  vector_directory = get_vector_directory(wolf, WIDTH/2);
  v_obj->x = tmp->pos->x - wolf->play->pos_player->x;
  v_obj->y = tmp->pos->y - wolf->play->pos_player->y;
  coss = (v_obj->x * vector_directory->x) + (v_obj->y * vector_directory->y);
  coss = coss / (get_norme(vector_directory) * get_norme(v_obj));
  size_op = tan(acos(coss)) * 0.5;
  rotate(vector_directory, wolf->play->deg_player * -1);
  rotate(v_obj, wolf->play->deg_player * -1);
  p1->x = (WIDTH/2) - (size_op * WIDTH) ;
  if (v_obj->y - vector_directory->y < 0)
    p1->x = (WIDTH/2) + (size_op * WIDTH);
  p1->y = 0;
  if (v_obj->x - vector_directory->x >= 0)
    display_object(wolf, p1, tmp);
}

void		place_object(t_wolf *wolf)
{
  int		nb_tok;
  int		x;
  int		y;
  t_image	*img;

  srand ( time(NULL) );
  nb_tok = (wolf->size_map * wolf->size_line_map) / 10;
  wolf->play->nb_tok = 0;
  wolf->play->max_tok = nb_tok;
  wolf->object = NULL;
  while (nb_tok > 0)
    {
      x = 0;
      y = 0;
      while (is_wall(x, y, wolf, 1))
	{
	  x = rand() % (wolf->size_line_map - 1);
	  y = rand() % (wolf->size_map - 1);
	}
      img = wolf->texture->wall_one;
      wolf->object = add_struct(wolf->object, x + 0.5, y + 0.5, img);
      nb_tok--;
    }
}

int	object_is_in(t_wolf *wolf, int x, int y)
{
  t_obj	*obj;

  obj = wolf->object;
  while (obj != NULL)
    {
      if ((int)obj->pos->x == x)
	if ((int)obj->pos->y == y)
	  return (1);
      obj = obj->next;
    }
  return (0);
}

void		check_object(t_wolf *wolf)
{
  t_obj		*obj;
  t_f_point	vector;
  float		dist;

  obj = wolf->object;
  while (obj != NULL)
    {
      vector.x = obj->pos->x - wolf->play->pos_player->x;
      vector.y = obj->pos->y - wolf->play->pos_player->y;
      dist = get_norme(&vector);
      if (dist < 0.5)
	{
	  wolf->play->nb_tok += 1;
	  wolf->object = remove_object(wolf->object, obj);
	  if (wolf->play->nb_tok == wolf->play->max_tok)
	    mlx_string_put(wolf->mlx, wolf->win, 500, 400, 255, "Gagné");
	}
      obj = obj->next;
    }
}

