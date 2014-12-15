/*
** keyboard.c for keyboard in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu Jan  3 16:25:06 2013 telenc_r
** Last update Sun Jan 13 00:21:04 2013 telenc_r
*/

#include	"wolf.h"

void	init_key_board(t_wolf *wolf)
{
  wolf->keyboard = my_malloc(sizeof(t_keyboard));
  wolf->keyboard->up = 0;
  wolf->keyboard->down = 0;
  wolf->keyboard->left = 0;
  wolf->keyboard->right = 0;
}
