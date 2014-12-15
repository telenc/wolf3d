/*
** mini_map.c for mini_map in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  9 17:44:40 2013 telenc_r
** Last update Sun Jan 13 23:00:16 2013 telenc_r
*/

#include	<mlx.h>
#include	"wolf.h"

unsigned long	get_color(t_i_point *map, t_wolf *wolf, t_i_point *pos,
			  t_f_point *play)
{
  t_f_point	*pos_p;

  pos_p = wolf->play->pos_player;
  if (wolf->map[map->x + (map->y * wolf->size_line_map)]->is_seen == 0)
    my_put_pixel_img(wolf, pos->x + 20, pos->y + 20, 0);
  else if (is_wall(map->x, map->y, wolf, 1))
    my_put_pixel_img(wolf, pos->x + 20, pos->y + 20, 0xA7A37E);
  else if ((int)pos_p->x == map->x && (int)pos_p->y == map->y)
    {
      play->x = pos->x + 20;
      play->y = pos->y + 20;
      my_put_pixel_img(wolf, pos->x + 20, pos->y + 20, 0xB9121B);
    }
  else if (object_is_in(wolf, map->x, map->y))
    my_put_pixel_img(wolf, pos->x + 20, pos->y + 20, 0xB5E655);
  else
    my_put_pixel_img(wolf, pos->x + 20, pos->y + 20, 0xF6E497);
}

void		display_angle(t_wolf *wolf, t_f_point *play)
{
  int		a;
  t_f_point	ang;
  t_i_point	pos;
  t_i_point	map;

  a = -20;
  while (a < 20)
    {
      ang.x = 20;
      ang.y = 0;
      rotate(&ang, wolf->play->deg_player + a);
      ang.x += play->x;
      ang.y += play->y;
      pos.x = (int)play->x;
      pos.y = (int)play->y;
      map.x = (int)ang.x;
      map.y = (int)ang.y;
      draw_line(wolf, &pos, &map, 0xCCCCCC);
      a++;
    }
}

void		display_mini_map(t_wolf *wolf)
{
  t_i_point	size_square;
  t_i_point	pos;
  t_i_point	map;
  t_f_point	play;

  pos.x = 0;
  size_square.x = 200 / (wolf->size_line_map);
  size_square.y = 200 / (wolf->size_map - 1);
  while (pos.x <= 200)
    {
      pos.y = 0;
      while (pos.y <= 200)
	{
	  map.x = pos.x / (size_square.x + 0);
	  map.y = pos.y / (size_square.y + 0);
	  if (map.x < wolf->size_line_map && map.y < wolf->size_map-1)
	    get_color(&map, wolf, &pos, &play);
	  pos.y += 1;
	}
      pos.x += 1;
    }
  play.y -= (size_square.y / 2);
  play.x -= (size_square.x / 2);
  display_angle(wolf, &play);
}
