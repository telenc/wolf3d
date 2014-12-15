/*
** my_putchar.c for my_putchar in /home/telenc_r/rendu/wolf/includes
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 11:32:37 2012 telenc_r
** Last update Fri Dec 21 11:37:27 2012 telenc_r
*/

#include	<unistd.h>
#include	"wolf.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    error_write();
}
