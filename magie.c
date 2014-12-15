/*
** magie.c for magie in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun Jan 13 11:20:05 2013 telenc_r
** Last update Sun Jan 13 14:57:50 2013 telenc_r
*/

#include	"wolf.h"

void		create_new_wall(t_wolf *wolf)
{
  int		x;
  t_f_point	*vect;
  t_f_point	pos;

  vect = get_vector_directory(wolf, WIDTH/2);
  pos.x = vect->x;
  pos.y = vect->y;
  pos.x += wolf->play->pos_player->x;
  pos.y += wolf->play->pos_player->y;
  while ((int)pos.x == (int)wolf->play->pos_player->x &&
	 (int)pos.y == (int)wolf->play->pos_player->y)
    {
      pos.x += vect->x * 0.1;
      pos.y += vect->y * 0.1;
    }
  if (!object_is_in(wolf, (int)pos.x, (int)pos.y))
    {
      if (!is_wall((int)pos.x, (int)pos.y, wolf, 1))
	{
	  wolf->map[(int)pos.x + ((int)pos.y * wolf->size_line_map)]->skin = 2;
	  wolf->map[(int)pos.x + ((int)pos.y * wolf->size_line_map)]->visible = 1;
	  wolf->map[(int)pos.x + ((int)pos.y * wolf->size_line_map)]->is_seen = 0;
	}
    }
}

void		delete_new_wall(t_wolf *wolf)
{
  int		x;
  t_f_point	*vect;
  t_f_point	pos;
  int		num;

  vect = get_vector_directory(wolf, WIDTH/2);
  pos.x = vect->x + wolf->play->pos_player->x;
  pos.y = vect->y + wolf->play->pos_player->y;
  while ((int)pos.x == (int)wolf->play->pos_player->x &&
	 (int)pos.y == (int)wolf->play->pos_player->y)
    {
      pos.x += vect->x * 0.1;
      pos.y += vect->y * 0.1;
    }
  if (!object_is_in(wolf, (int)pos.x, (int)pos.y))
    {
      if ((int)pos.x > 0 && (int)pos.x < wolf->size_line_map - 1)
	if ((int)pos.y > 0 && (int)pos.y < wolf->size_map - 2)
	  {
	    num = (int)pos.x + ((int)pos.y * wolf->size_line_map);
	    wolf->map[num]->skin = 0;
	    wolf->map[num]->visible = 0;
	    wolf->map[num]->is_seen = 0;
	  }
    }
}
