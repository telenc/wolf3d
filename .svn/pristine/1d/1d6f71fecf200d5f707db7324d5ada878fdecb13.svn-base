/*
** str.c for str in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sat Jan  5 19:38:22 2013 telenc_r
** Last update Sun Jan 13 16:26:08 2013 telenc_r
*/

#include	<stdlib.h>
#include	"wolf.h"

int	number_oc_char(char *str, char c)
{
  int	result;
  int	i;

  i = 0;
  result = 0;
  while (str[i] != '\0')
    if (str[i++] == c)
      result++;
  return (result);
}

int	get_position_next_char(char *str, int i, char c)
{
  int	result;

  result = 1;
  while (str[i] != '\0' && str[i] != c)
    {
      i++;
      result++;
    }
  result++;
  return (result + 4);
}

char	**my_split_str(char *str, char c)
{
  char	**result;
  char	*tmp;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  result = my_malloc(sizeof(char *) * (number_oc_char(str, c) + 2));
  tmp = my_malloc(sizeof(char) * get_position_next_char(str, i, c) + 2);
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  result[j++] = tmp;
	  tmp = my_malloc(sizeof(char) * get_position_next_char(str, i++, c));
	  k = 0;
	}
      tmp[k++] = str[i++];
      tmp[k] = '\0';
    }
  result[j++] = tmp;
  result[j] = NULL;
  return (result);
}
