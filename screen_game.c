/*
** screen_game.c for screen_game in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sat Jan 12 18:29:36 2013 telenc_r
** Last update Sun Jan 13 23:02:33 2013 telenc_r
*/

#include	<unistd.h>
#include	<time.h>
#include	"wolf.h"

int	finish_game(t_wolf *wolf)
{
  mlx_put_image_to_window(wolf->mlx, wolf->win,
			  wolf->texture->win->image, 0, 0);
  wolf->screen = 3;
  wolf->play->nb_tok = 0;
  return (1);
}

int	loose_game(t_wolf *wolf)
{
  mlx_put_image_to_window(wolf->mlx, wolf->win,
			  wolf->texture->loose->image, 0, 0);
  wolf->screen = 3;
  wolf->play->nb_tok = 0;
  return (1);
}

void		screen_time(t_wolf *wolf)
{
  static time_t	start = 0;
  static int	last_game = -1;
  time_t	end;
  char		*hor;
  int		num;
  int		compt;
  t_i_point	p;

  if (start == 0 || last_game != wolf->play->num_game)
    start = clock();
  last_game = wolf->play->num_game;
  end = clock();
  hor = my_nbr_to_char(180 - ((end - start) / CLOCKS_PER_SEC));
  if ((int)(180 - ((end - start) / CLOCKS_PER_SEC)) == 0)
    loose_game(wolf);
  num = my_strlen(hor);
  compt = 1;
  while (num > 0)
    {
      p.x = 1000 - (50 * compt);
      p.y = 50;
      my_put_all_img(get_img(wolf, hor[num - 1]), wolf, &p, 50);
      compt++;
      num--;
    }
}

void		screen_hand(t_wolf *wolf)
{
  t_image	*img;
  t_i_point	p;

  img = wolf->texture->hand;
  if (wolf->play->nb_tok > 0)
    img = wolf->texture->hand_tok;
  p.x = (WIDTH) - 280;
  p.y = (HEIGHT) - 300;
  my_put_all_img(img, wolf, &p, 300);
  img = wolf->texture->hand_left;
  if (wolf->play->nb_tok > 1)
    img = wolf->texture->hand_left_tok;
  p.x = -20;
  p.y = (HEIGHT) - 300;
  my_put_all_img(img, wolf, &p, 300);
}

int		screen_game(t_wolf *wolf)
{
  char		*nb_tok;
  char		*nb_tok_max;
  int		num;
  t_image	*img;
  t_i_point	p;
  int		compt;

  if (wolf->play->nb_tok == wolf->play->max_tok)
    return (finish_game(wolf));
  nb_tok = my_nbr_to_char(wolf->play->nb_tok);
  nb_tok_max = my_nbr_to_char(wolf->play->max_tok);
  nb_tok = my_strcat(my_strcat(nb_tok, "/", 0), nb_tok_max, 3);
  num = my_strlen(nb_tok);
  compt = 1;
  while (num > 0)
    {
      p.x = 1000 - (50 * compt);
      p.y = 800 - 50;
      img = get_img(wolf, nb_tok[num - 1]);
      my_put_all_img(img, wolf, &p, 50);
      compt++;
      num--;
    }
  screen_hand(wolf);
  screen_time(wolf);
}
