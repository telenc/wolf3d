/*
** menu.c for menu in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Jan 11 19:35:47 2013 telenc_r
** Last update Sun Jan 13 22:59:49 2013 telenc_r
*/

#include	<stdlib.h>
#include	<mlx.h>
#include	"wolf.h"

int		verif_pos(t_wolf *wolf)
{
  t_f_point	*pos;
  int		x;
  int		y;

  x = 0;
  while (x < wolf->size_line_map)
    {
      y = 0;
      while (y < wolf->size_map - 1)
	{
	  if (!is_wall(x, y, wolf, 1))
	    {
	      wolf->play->pos_player->x = x + 0.5;
	      wolf->play->pos_player->y = y + 0.5;
	      return (0);
	    }
	  y++;
	}
      x++;
    }
  error_file();
  return (1);
}

void	load(t_wolf *wolf)
{
  if (wolf->object == NULL)
    place_object(wolf);
}

void	init_load(t_wolf *wolf)
{
  void	*img;
  int	w;
  int	h;
  int	bpp;
  int	size_line;
  int	endian;

  wolf->screen = 1;
  w = 1000;
  h = 800;
  if (wolf->texture == NULL)
    {
      wolf->texture = my_malloc(sizeof(t_texture));
      wolf->texture->load = NULL;
      wolf->texture->wall_one = NULL;
    }
  if (wolf->texture->load == NULL)
    wolf->texture->load = create_texture("texture/load.xpm", wolf);
  if (wolf->texture->wall_one == NULL)
    init_texture(wolf);
  mlx_put_image_to_window(wolf->mlx, wolf->win,
			  wolf->texture->load->image, 0, 0);
}
