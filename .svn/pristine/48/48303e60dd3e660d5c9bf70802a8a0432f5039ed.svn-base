/*
** verif.c for verif in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 16:01:25 2012 telenc_r
** Last update Sun Jan 13 17:39:30 2013 telenc_r
*/
#include	"wolf.h"

int	is_ok(char c)
{
  if (c == '/')
    return (1);
  if (c == '.')
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

void	verif(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '/')
    error_file();
  if (str[my_strlen(str)] == '/')
    error_file();
  while (str[i] != '\0')
    {
      if (str[i] == '/' || str[i] == '.')
	if (str[i + 1] == '/' || str[i + 1] == '.')
	  error_file();
      if (!is_ok(str[i]))
	error_file();
      i++;
    }
}

void	verif_map(t_wolf *wolf)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (x < wolf->size_line_map)
    {
      if (!is_wall(x, y, wolf, 1))
	error_file();
      if (!is_wall(x, wolf->size_map - 2, wolf, 1))
	error_file();
      x++;
    }
  x = 0;
  y = 0;
  while (y < wolf->size_map - 1)
    {
      if (!is_wall(x, y, wolf, 1))
	error_file();
      if (!is_wall(wolf->size_line_map - 1, y, wolf, 1))
	error_file();
      y++;
    }
}
