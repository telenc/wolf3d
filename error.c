/*
** error.c for error in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 15:54:10 2012 telenc_r
** Last update Sun Jan  6 19:03:28 2013 telenc_r
*/

#include	<stdlib.h>
#include	"wolf.h"

void	error_malloc()
{
  my_putstr("Erro malloc\n");
  exit(40);
}

void	error_write()
{
  my_putstr("Error write\n");
  exit(41);
}

void	error_file()
{
  my_putstr("Error file\n");
  exit(42);
}

void	error_minilibx()
{
  my_putstr("Error minilibx\n");
  exit(43);
}

void	error_texture()
{
  my_putstr("Error texture\n");
  exit(43);
}
