/*
** my_put_pixel_two.c for my_put_pixel_two in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun Jan 13 15:13:54 2013 telenc_r
** Last update Sun Jan 13 23:05:06 2013 telenc_r
*/

#include	"wolf.h"

void    my_put_pixel_img(t_wolf *fdf, int x, int y, unsigned long color)
{
  int   i;

  i = 0;
  if (y > 0 && x > 0 && y < HEIGHT && x < WIDTH)
    {
      while (i < fdf->bpp/8 )
        {
          fdf->data[(fdf->size_line * y) + (x * fdf->bpp/8) + i] = color;
          color = color>>8;
          i++;
        }
    }
}

int	is_alpha(t_f_point *p_w, t_wall *wall, t_wolf *fdf)
{
  int	i;
  int	ok;
  int	size_line;
  int	bpp;
  char *data;

  data = wall->texture->data;
  size_line = wall->texture->size_line;
  bpp = wall->texture->bpp;
  ok = 0;
  i = 0;
  if (data[(size_line *(int)p_w->y) + ((int)p_w->x * bpp/8) + i++] == 255)
    ok = 1;
  while (i < fdf->bpp/8 )
    if (data[(size_line *(int)p_w->y) + ((int)p_w->x * bpp/8) + i++] != 0)
      ok = 0;
  return (ok);
}

void		display_px(t_wall *wall, t_f_point *pw, t_wolf *wo, t_i_point *pf)
{
  int		i;
  int		size_line;
  int		omb;
  int		size_img;
  t_image	*t;

  t = wall->texture;
  omb = 20;
  if (wall->type_shoot == 2)
    omb = 0;
  i = 0;
  while (i < wo->bpp/8)
    {
      size_line = (t->size_line *(int)pw->y) + ((int)pw->x * t->bpp/8) + i;
      size_img = (wo->size_line * pf->y) + (pf->x * wo->bpp/8) + i;
      if (t->data[size_line] + omb > 0 && i < 4)
	if (t->data[size_line] + omb < 0)
	  wo->data[size_img] = 0;
	else
	  wo->data[size_img] = t->data[size_line] + omb;
      else
	wo->data[size_img] = t->data[size_line];
      i = i + 1;
    }
}

void		my_put_pixel_img_wall(t_wolf *wo, int x, int y, t_wall *wall)
{
  t_image	*t;
  int		i;
  t_f_point	pw;
  int		size_line;
  int		ok;
  int		omb;
  t_i_point	pf;

  pf.x = x;
  pf.y = y;
  t = wall->texture;
  pw.x = (wall->y_shoot - (int)(wall->y_shoot)) * 512;
  if (wall->type_shoot == 2)
    pw.x = (wall->x_shoot - (int)(wall->x_shoot)) * 512;
  pw.y = y - ((WIDTH / 2) - wall->height_wall) + 100;
  pw.y = (512 / wall->height_wall) / 2 * pw.y;
  if (pw.y >= 512 || pw.y < 0)
    pw.y = 0;
  ok = is_alpha(&pw, wall, wo);
  i = 0;
  if (pf.y > 0 && ok == 0 && pf.x > 0 && pf.y < HEIGHT && pf.x < WIDTH)
    display_px(wall, &pw, wo, &pf);
}
