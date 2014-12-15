/*
** draw_line.c for draw_line in /home/telenc_r/rendu/fdf/fdf-2017-telenc_r
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Tue Dec  4 18:01:15 2012 telenc_r
** Last update Sun Jan 13 22:58:20 2013 telenc_r
*/

#include	"wolf.h"

int	cas_deux_wall(t_wolf *fdf, t_i_point *p1, t_i_point *p2, t_wall *wall)
{
  int	y;
  int	x;

  y = p1->y;
  if (y < 0)
    y = 0;
  while (y <= p2->y)
    {
      if (y > 0)
	{
	  if ((p2->y - p1->y) == 0)
	    p1->y += 1;
	  x = p1->x + ((p2->x - p1->x) * (y-p1->y) / (p2->y - p1->y));
	  if (x > 0 && x <= WIDTH)
	    my_put_pixel_img_wall(fdf, x, y, wall);
	}
      y++;
      if (y > HEIGHT)
	return (1);
    }
  return (0);
}

void	draw_line_wall(t_wolf *fdf, t_i_point *p1, t_i_point *p2, t_wall *wall)
{
  if (p1->y < p2->y && (p2->y - p1->y) >= abs(p2->x - p1->x))
    cas_deux_wall(fdf, p1, p2, wall);
}
