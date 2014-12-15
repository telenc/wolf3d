/*
** draw_line.c for draw_line in /home/telenc_r/rendu/fdf/fdf-2017-telenc_r
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Tue Dec  4 18:01:15 2012 telenc_r
** Last update Sun Jan 13 14:52:20 2013 telenc_r
*/

#include	"wolf.h"

int	abs(int i)
{
  if (i < 0)
    return (i * -1);
  return (i);
}

void		draw_line(t_wolf *fdf, t_i_point *p1,
			  t_i_point *p2, unsigned long color)
{
  t_i_point	*p3;

  if (p1->x < p2->x && (p2->x - p1->x) >= abs(p2->y - p1->y))
    cas_un(fdf, p1, p2, color);
  else if (p1->x > p2->x && (p1->x - p2->x) >= abs(p2->y - p1->y))
    {
      p3 = p1;
      p1 = p2;
      p2 = p3;
      cas_un(fdf, p1, p2, color);
    }
  else if (p1->y < p2->y && (p2->y - p1->y) >= abs(p2->x - p1->x))
    cas_deux(fdf, p1, p2, color);
  else
    {
      p3 = p1;
      p1 = p2;
      p2 = p3;
      cas_deux(fdf, p1, p2, color);
    }
}

int	cas_un(t_wolf *fdf, t_i_point *p1, t_i_point *p2, unsigned long color)
{
  int	x;
  int	y;

  x = p1->x;
  while (x <= p2->x)
    {
      if (x < 0)
	return (1);
      if (p2->x - p1->x == 0)
	p1->x += 1;
      y = p1->y + ((p2->y - p1->y) * (x-p1->x) / (p2->x - p1->x));
      my_put_pixel_img(fdf, x, y, color);
      x++;
    }
  return (0);
}

int	cas_deux(t_wolf *fdf, t_i_point *p1, t_i_point *p2, unsigned long color)
{
  int	y;
  int	x;

  y = p1->y;
  while (y <= p2->y)
    {
      if (y < 0)
	return (1);
      if ((p2->y - p1->y) == 0)
      	p1->y += 1;
      x = p1->x + ((p2->x - p1->x) * (y-p1->y) / (p2->y - p1->y));
      my_put_pixel_img(fdf, x, y, color);
      y++;
    }
  return (0);
}
