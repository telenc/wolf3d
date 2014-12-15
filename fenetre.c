/*
** fenetre.c for fenetre in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  2 14:46:32 2013 telenc_r
** Last update Sun Jan 13 22:06:34 2013 telenc_r
*/

#include	<stdlib.h>
#include	<mlx.h>
#include	<X11/X.h>
#include	<time.h>
#include	"wolf.h"

t_image		*create_texture(char *path, t_wolf *wolf)
{
  t_image	*result;
  int		w;
  int		h;
  int		bpp;
  int		size_line;
  int		endian;

  w = 512;
  h = 512;
  result = my_malloc(sizeof(t_image));
  if (wolf->mlx == NULL)
    error_minilibx();
  result->image = mlx_xpm_file_to_image(wolf->mlx, path, &w, &h);
  if (result->image == NULL)
    error_minilibx();
  result->data = mlx_get_data_addr(result->image, &bpp, &size_line, &endian);
  result->bpp = bpp;
  result->size_line = size_line;
  result->endian = endian;
  return (result);
}

void		init_image(t_wolf *wolf)
{
  static int	fp = 25;

  fp += 1;
  usleep(1000);
  if (fp >= 25)
    {
      wolf->screen = 2;
      draw_sky(wolf);
      draw_floor(wolf);
      draw_wall(wolf);
      init_object(wolf);
      display_mini_map(wolf);
      mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
      screen_game(wolf);
      fp = 0;
    }
}

void	init_texture(t_wolf *wolf)
{
  wolf->texture->wall_one = create_texture("texture/1.xpm", wolf);
  wolf->texture->wall_two = create_texture("texture/2.xpm", wolf);
  wolf->texture->wall_three = create_texture("texture/3.xpm", wolf);
  wolf->texture->wall_four = create_texture("texture/4.xpm", wolf);
  wolf->texture->nb0 = create_texture("texture/n0.xpm", wolf);
  wolf->texture->nb1 = create_texture("texture/n1.xpm", wolf);
  wolf->texture->nb2 = create_texture("texture/n2.xpm", wolf);
  wolf->texture->nb3 = create_texture("texture/n3.xpm", wolf);
  wolf->texture->nb4 = create_texture("texture/n4.xpm", wolf);
  wolf->texture->nb5 = create_texture("texture/n5.xpm", wolf);
  wolf->texture->nb6 = create_texture("texture/n6.xpm", wolf);
  wolf->texture->nb7 = create_texture("texture/n7.xpm", wolf);
  wolf->texture->nb8 = create_texture("texture/n8.xpm", wolf);
  wolf->texture->nb9 = create_texture("texture/n9.xpm", wolf);
  wolf->texture->nbs = create_texture("texture/ns.xpm", wolf);
  wolf->texture->win = create_texture("texture/win.xpm", wolf);
  wolf->texture->loose = create_texture("texture/loose.xpm", wolf);
  wolf->texture->hand = create_texture("texture/hand.xpm", wolf);
  wolf->texture->hand_left = create_texture("texture/hand2.xpm", wolf);
  wolf->texture->hand_tok = create_texture("texture/hand11.xpm", wolf);
  wolf->texture->hand_left_tok = create_texture("texture/hand21.xpm", wolf);
}

int	hook_ex(t_wolf *wolf)
{
  if (wolf->screen == 2)
    {
      mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
      screen_game(wolf);
    }
  else
    init_load(wolf);
}

void	init_fenetre(t_wolf *wolf)
{
  int	size_l;
  int	endian;

  wolf->mlx = mlx_init();
  if (wolf->mlx == NULL)
    error_minilibx();
  wolf->win = mlx_new_window(wolf->mlx, WIDTH, HEIGHT, "Wolf telenc_r");
  if (wolf->win == NULL)
    error_minilibx();
  wolf->img = mlx_new_image(wolf->mlx, WIDTH, HEIGHT);
  wolf->data = mlx_get_data_addr(wolf->img, &(wolf->bpp), &size_l, &endian);
  wolf->size_line = size_l;
  wolf->endian = endian;
  wolf->object = NULL;
  init_load(wolf);
  mlx_mouse_hook(wolf->win, &mouse_hook, wolf);
  mlx_expose_hook(wolf->mlx, &hook_ex, wolf);
  mlx_hook(wolf->win, KeyPress, KeyPressMask, &key_code, wolf);
  mlx_hook(wolf->win, KeyRelease, KeyReleaseMask, &key_release, wolf);
  mlx_loop_hook(wolf->mlx, &loop_hook, wolf);
  mlx_loop(wolf->mlx);
}
