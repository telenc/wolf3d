/*
** main.c for main in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 15:49:23 2012 telenc_r
** Last update Sun Jan 13 17:36:35 2013 telenc_r
*/

#include <string.h>

#include	<stdio.h>
#include	<mlx.h>
#include	"wolf.h"

char	*my_strcpy(char *dst, char *src)
{
  int	i;

  while (src[i] != '\0')
    dst[i] = src[i++];
  dst[i] = '\0';
  return (dst);
}

char	*my_strncpy(char *dst, char *src, int n)
{
  int	i;

  while (i < n && src[i] != '\0')
    dst[i] = src[i++];
  dst[i] = '\0';
  return (dst);
}

size_t	strlcpy(char *dst, char *src, size_t dstsize)
{
  if (my_strlen(src) < dstsize)
    my_strcpy(dst, src);
  else
    {
      my_strncpy(dst, src, dstsize - 1);
      dst[dstsize - 1] = '\0';
    }
  return (my_strlen(src));
}

int		main(int argc, char **argv)
{
  t_wolf	*wolf;

  my_nbr_to_char(45388);
  wolf = my_malloc(sizeof(t_wolf));
  wolf->size_map = 0;
  wolf->play = NULL;
  wolf->texture = NULL;
  if (argc == 2)
    wolf->map = create_map(argv[1], wolf);
  verif_map(wolf);
  init_pos_player(wolf);
  init_key_board(wolf);
  init_fenetre(wolf);
  return (1);
}
