/*
** my_nbr_to_char.c for my_nbr_to_char in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sat Jan 12 18:09:37 2013 telenc_r
** Last update Sun Jan 13 15:05:39 2013 telenc_r
*/

#include	"wolf.h"

char	*my_nbr_to_char(int nbb)
{
  char	*result;
  int	num;
  int	nb;

  nb = nbb;
  num = 0;
  while (nbb > 0)
    {
      num++;
      nbb /= 10;
    }
  if (num == 0)
    return ("0");
  result = my_malloc(sizeof(char) * (num + 2));
  result[num] = '\0';
  while (nb > 0)
    {
      result[num - 1] = nb%10 + '0';
      nb = nb / 10;
      num--;
    }
  return (result);
}

t_image	*get_img(t_wolf *wolf, char c)
{
  if (c == '0')
    return (wolf->texture->nb0);
  if (c == '1')
    return (wolf->texture->nb1);
  if (c == '2')
    return (wolf->texture->nb2);
  if (c == '3')
    return (wolf->texture->nb3);
  if (c == '4')
    return (wolf->texture->nb4);
  if (c == '5')
    return (wolf->texture->nb5);
  if (c == '6')
    return (wolf->texture->nb6);
  if (c == '7')
    return (wolf->texture->nb7);
  if (c == '8')
    return (wolf->texture->nb8);
  if (c == '9')
    return (wolf->texture->nb9);
  if (c == '/')
    return (wolf->texture->nbs);
}
