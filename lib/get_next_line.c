/*
** get_next_line.c for get_next_line in /home/telenc_r/rendu/getnextline
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Mon Dec 17 11:09:33 2012 telenc_r
** Last update Sun Jan 13 23:06:21 2013 telenc_r
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"wolf.h"
#include	"get_next_line.h"

t_gnl	*add_struct_gnl(t_gnl *c, char new)
{
  t_gnl	*new_c;
  t_gnl	*cur;

  cur = c;
  new_c = my_malloc(sizeof(t_gnl));
  new_c->c = new;
  new_c->next = NULL;
  if (cur != NULL)
    {
      while (cur->next != NULL)
	cur = cur->next;
      cur->next = new_c;
      return (c);
    }
  return (new_c);
}

int	get_next_bn(t_gnl *list)
{
  int	result;
  t_gnl	*cur;

  result = 0;
  cur = list;
  while (cur != NULL)
    {
      if (cur->c != '\n')
	result++;
      else
	return (result);
      cur = cur->next;
    }
  return (result);
}

int	contain_bn(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	  return (1);
      i++;
    }
  return (0);
}

t_gnl	*read_fic(const int fd, t_gnl *gnl)
{
  char	*buffer;
  int	i;
  int	ret;

  buffer = my_malloc(sizeof(char) * (MAX_READ + 2));
  ret = read(fd, buffer, MAX_READ);
  while (ret != 0)
    {
      i = 0;
      buffer[ret] = '\0';
      while (buffer[i] != '\0')
	gnl = add_struct_gnl(gnl, buffer[i++]);
      if (contain_bn(buffer) == 1)
	ret = 0;
      else
	ret = read(fd, buffer, MAX_READ);
    }
  free(buffer);
  return (gnl);
}

char		*get_next_line(const int fd)
{
  static t_gnl	*gnl = NULL;
  int		k;
  char		*result;
  t_gnl		*sauv;

  gnl = read_fic(fd, gnl);
  result = my_malloc(sizeof(char) * (get_next_bn(gnl) + 2));
  k = 0;
  while (gnl != NULL)
    {
      sauv = gnl;
      result[k++] = gnl->c;
      gnl = gnl->next;
      free(sauv);
      if (result[k - 1] == '\n')
	{
	  result[k - 1] = '\0';
	  return (result);
	}
    }
  result[k] = '\0';
  if (k != 0)
    return (result);
  free(result);
  return (NULL);
}
