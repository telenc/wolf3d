/*
** create_map.c for create_map in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 15:49:40 2012 telenc_r
** Last update Sun Jan 13 22:57:28 2013 telenc_r
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"wolf.h"

void	init_map(t_wolf *wolf)
{
  int	i;

  i = 0;
  while (wolf->map[i] != NULL)
    wolf->map[i++]->is_seen = 0;
}

void	my_put_doublechar(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      my_putstr(str[i]);
      my_putstr("\n");
      i++;
    }
}

char	*create_map_str(char *path, t_wolf *wolf, char *result)
{
  int	fd;
  char	*s;

  result = NULL;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    error_file();
  while ((s = get_next_line(fd)))
    {
      if (result != NULL)
	if (wolf->size_line_map != number_oc_char(s, '/') + 1)
	  error_file();
	else
	  result = my_strcat(result, s, 3);
      else
	{
	  result = s;
	  wolf->size_line_map = number_oc_char(s, '/') + 1;
	}
      result = my_strcat(result, "/", 1);
      wolf->size_map++;
    }
  if (result == NULL)
    error_file();
  return (result);
}

t_map	**create_map_struct(char **map_str)
{
  t_map	**result;
  t_map	*tmp;
  char	**tmp_char;
  int	i;
  int	j;

  j = 0;
  i = 0;
  result = my_malloc(sizeof(t_map *) * (my_strlen_double_char(map_str) + 2));
  while (map_str[i] != NULL)
    {
      tmp = my_malloc(sizeof(t_map));
      if (number_oc_char(map_str[i], '.') != 2)
	error_file();
      tmp_char = my_split_str(map_str[i], '.');
      tmp->skin = my_getnbr(tmp_char[0]);
      tmp->visible = my_getnbr(tmp_char[1]);
      tmp->size = my_getnbr(tmp_char[2]);
      tmp->is_seen = 0;
      free(tmp_char);
      result[j++] = tmp;
      i++;
    }
  result[j] = NULL;
  return (result);
}

t_map	**create_map(char *path, t_wolf *wolf)
{
  char	*map_str;
  char	**map_str_str;
  t_map	**result;

  map_str = create_map_str(path, wolf, NULL);
  map_str[my_strlen(map_str) - 1] = '\0';
  wolf->size_map++;
  verif(map_str);
  map_str_str = my_split_str(map_str, '/');
  result = create_map_struct(map_str_str);
  free(map_str_str);
  free(map_str);
  if (wolf->size_map - 1 < 3 || wolf->size_line_map < 3)
    error_file();
  return (result);
}
