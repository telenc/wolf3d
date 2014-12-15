/*
** struct.c for struct in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed Jan  9 15:53:09 2013 telenc_r
** Last update Sun Jan 13 22:06:33 2013 telenc_r
*/

#include	<stdlib.h>
#include	"wolf.h"

void	init_object(t_wolf *wolf)
{
  t_obj	*tmp;

  tmp = wolf->object;
  while (tmp != NULL)
    {
      draw_object(wolf, tmp);
      tmp = tmp->next;
    }
}

t_obj	*remove_object(t_obj *env, t_obj *obj)
{
  t_obj	*tmp;
  t_obj	*sauv;

  tmp = env;
  while (tmp != obj && tmp != NULL)
    {
      sauv = tmp;
      tmp = tmp->next;
    }
  if (tmp == env)
    return (tmp->next);
  if (tmp == NULL)
    return (env);
  sauv->next = tmp->next;
  free(tmp);
  return (env);
}

t_obj   *add_struct(t_obj *env, float x, float y, t_image *text)
{
  t_obj	*result;
  t_obj *sauv;

  sauv = env;
  result = my_malloc(sizeof(t_obj));
  result->pos = my_malloc(sizeof(t_f_point));
  result->pos->x = x;
  result->pos->y = y;
  result->texture = text;
  result->next = NULL;
  if (env == NULL)
    return (result);
  while (env->next != NULL)
    env = env->next;
  env->next = result;
  return (sauv);
}

