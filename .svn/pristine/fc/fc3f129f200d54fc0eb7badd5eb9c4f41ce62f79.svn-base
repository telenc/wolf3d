/*
** calc2.c for calc2 in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sat Jan 12 23:59:45 2013 telenc_r
** Last update Sun Jan 13 00:00:15 2013 telenc_r
*/

#include	<math.h>
#include	"wolf.h"

float	get_norme(t_f_point *p1)
{
  float	a;
  float	b;

  a = (p1->x) * (p1->x);
  b = (p1->y) * (p1->y);
  return (sqrt(a + b));
}

void	rotate(t_f_point *vec, int angle)
{
  float	sauv_x;
  float	sauv_y;

  sauv_y = vec->y;
  sauv_x = vec->x;
  vec->x = (sauv_x * cos(RAD(angle))) - (sauv_y * sin(RAD(angle)));
  vec->y = (sauv_x * sin(RAD(angle))) + (sauv_y * cos(RAD(angle)));
}

