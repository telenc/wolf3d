/*
** my_put_pixel.c for my_put_pixel in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  2 16:00:38 2013 telenc_r
** Last update Sun Jan 13 15:14:44 2013 telenc_r
*/

#include	<stdlib.h>
#include	<mlx.h>
#include	"wolf.h"

int	is_alpha_img(int x, int y, t_image *img_src, t_i_point *point)
{
  int	size_line;
  int	bpp;
  char *data;
  int   i;
  int	ok;

  size_line = img_src->size_line;
  bpp = img_src->bpp;
  data = img_src->data;
  i = 0;
  ok = 0;
  if (point->y >= 0 && point->x >= 0 && y < HEIGHT && x < WIDTH)
    {
      if (data[(size_line *(int)point->y) + ((int)point->x
					     * bpp/8) + i++] != 0)
	ok = 1;
      while (i < img_src->bpp/8 )
	if (data[(size_line *(int)point->y) + ((int)point->x
					       * bpp/8) + i++] != 0)
	  ok = 0;
    }
  return (ok);
}

int	img_to_img_two(t_i_point *p_img, t_i_point *pos,
		       t_image *img, t_wolf *wolf)
{
  int	ok;
  int	s_l;
  int	i;
  int	num;

  while (p_img->y < 512)
    {
      ok = is_alpha_img(pos->x, pos->y, img, p_img);
      i = 0;
      if (pos->y > 0 && ok == 0 && pos->x > 0 &&
	  pos->y < HEIGHT && pos->x < WIDTH)
	while (i < wolf->bpp/8 )
	  {
	    s_l = (img->size_line *(int)p_img->y) + ((int)p_img->x
						     * img->bpp/8) + i;
	    num = (wolf->size_line * pos->y) + (pos->x * wolf->bpp/8) + i++;
	    if (num >= 0 && s_l >= 0)
	      wolf->data[num] = img->data[s_l];
	  }
      if (wolf->k < 0)
	return (0);
      p_img->y += 512 / (HEIGHT / (2*wolf->k));
      pos->y += 1;
    }
}

int		my_put_img_to_img(t_image *img, t_wolf *wolf, t_i_point *p, float k)
{
  t_i_point	*p_img;
  t_i_point	*pos;
  t_f_point	*vector;
  t_wall	*wall;

  wolf->k = k;
  p_img = my_malloc(sizeof(t_i_point));
  pos = my_malloc(sizeof(t_i_point));
  pos->x = p->x - ((HEIGHT / (2 * k))/2);
  p_img->x = 0;
  while (p_img->x < 512)
    {
      vector = get_vector_directory(wolf, pos->x);
      if (pos->x > WIDTH)
	return (0);
      wall = get_wall(vector, wolf, 1);
      if (wall->height_wall > k)
	{
	  p_img->y = 0;
	  pos->y = (HEIGHT/2);
	  img_to_img_two(p_img, pos, img, wolf);
	}
      p_img->x +=  512 / (HEIGHT / (2*k));
      pos->x += 1;
    }
}

void		put_all_img_two(int x, t_image *img, t_wolf *wolf, t_i_point *p)
{
  int		y;
  t_i_point	pos;
  int		ok;
  int		i;
  int		s_l;
  int		num;

  y = -1;
  while (y++ < (int)wolf->k)
    {
      pos.x = x;
      pos.y = y;
      ok = is_alpha_img(p->x, p->y, img, &pos);
      if (ok == 0 && p->x > 0 && p->x < WIDTH && p->y > 0 && p->y < HEIGHT)
	{
	  i = 0;
	  while (i < img->bpp / 8)
	    {
	      s_l = (img->size_line *(int)y) + ((int)x * img->bpp/8) + i;
	      num = (wolf->size_line * p->y) + (p->x * wolf->bpp/8) + i++;
	      wolf->data[num] = img->data[s_l];
	    }
	}
      p->y += 1;
    }
}

void	my_put_all_img(t_image *img, t_wolf *wolf, t_i_point *p, int size)
{
  int	x;
  int	y;
  int	sauv_y;

  wolf->k = size;
  sauv_y = p->y;
  x = 0;
  while (x < size)
    {
      y = 0;
      p->y = sauv_y;
      put_all_img_two(x, img, wolf, p);
      p->x += 1;
      x++;
    }
}
