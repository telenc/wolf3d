/*
** my_putstr.c for my_putstr in /home/telenc_r/rendu/wolf/lib
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 11:31:27 2012 telenc_r
** Last update Fri Dec 21 11:37:00 2012 telenc_r
*/

#include	"wolf.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    my_putchar(str[i++]);
}
