/*
** my_strlen.c for my_strlen in /home/telenc_r/rendu/wolf/includes
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 11:33:54 2012 telenc_r
** Last update Sun Jan  6 16:14:35 2013 telenc_r
*/

#include	<stdlib.h>
#include	"wolf.h"

int	my_strlen_double_char(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
