/*
** keycode.c for keycode in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  2 20:34:37 2013 telenc_r
** Last update Sun Jan 13 22:59:14 2013 telenc_r
*/

#include	<stdlib.h>
#include	<time.h>
#include	"wolf.h"

int	mouse_hook(int button, int x, int y, t_wolf *wolf)
{
  if (button == 1)
    {
      if (wolf->screen == 1 && x > 90 && x < 290 && y > 290 && y < 350)
	{
	  mlx_clear_window(wolf->mlx, wolf->win);
	  wolf->screen = 2;
	  load(wolf);
	  init_image(wolf);
	}
      else if (wolf->screen == 1 && x > 200 && y > 400 && x < 400 && y < 460)
	exit (42);
      else if (wolf->screen == 2)
	create_new_wall(wolf);
      else if (wolf->screen == 3)
	{
	  wolf->screen = 1;
	  init_pos_player(wolf);
	  init_map(wolf);
	  place_object(wolf);
	  init_load(wolf);
	  wolf->play->num_game += 10;
	}
    }
  else if (button == 3 && wolf->screen == 2)
    delete_new_wall(wolf);
}

int		loop_hook(t_wolf *wolf)
{
  t_f_point	sauv;

  if (wolf->screen == 1 || wolf->screen == 3)
    return (1);
  sauv.x = wolf->play->pos_player->x;
  sauv.y = wolf->play->pos_player->y;
  if (wolf->keyboard->up)
    change_pos_up(wolf);
  if (wolf->keyboard->down)
    change_pos_down(wolf);
  if (sauv.x != wolf->play->pos_player->x ||
      sauv.y != wolf->play->pos_player->y)
    if (!(wolf->keyboard->left || wolf->keyboard->right))
      init_image(wolf);
  if (wolf->keyboard->left)
    change_deg(wolf, 1);
  if (wolf->keyboard->right)
    change_deg(wolf, -1);
  return (1);
}

int	key_code(int key, t_wolf *wolf)
{
  if (key == 65307)
    quit_wolf(wolf);
  if (key == 65361)
    wolf->keyboard->left = 1;
  if (key == 65363)
      wolf->keyboard->right = 1;
  if (key == 65362)
    wolf->keyboard->up = 1;
  if (key == 65364)
    wolf->keyboard->down = 1;
  return (1);
}

int	key_release(int key, t_wolf *wolf)
{
  if (key == 65361)
    wolf->keyboard->left = 0;
  if (key == 65363)
    wolf->keyboard->right = 0;
  if (key == 65362)
    wolf->keyboard->up = 0;
  if (key == 65364)
    wolf->keyboard->down = 0;
  return (1);
}
