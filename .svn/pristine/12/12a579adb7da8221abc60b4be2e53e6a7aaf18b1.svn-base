/*
** malloc.c for malloc in /home/telenc_r/rendu/wolf/includes
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 11:35:00 2012 telenc_r
** Last update Thu Jan 10 16:28:28 2013 telenc_r
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"wolf.h"

void	*my_malloc(int size)
{
  void	*result;

  result = malloc(size);
  if (result == NULL)
    error_malloc();
  return (result);
}

void	quit_wolf(t_wolf *wolf)
{
  free(wolf->map);
  free(wolf->play->pos_player);
  free(wolf->play);
  free(wolf->keyboard);
  free(wolf->texture->wall_one);
  free(wolf->texture);
  free(wolf);
  exit(42);
}
