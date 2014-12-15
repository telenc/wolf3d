/*
** player.c for player in /home/telenc_r/rendu/wolf
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri Dec 21 16:13:28 2012 telenc_r
** Last update Sun Jan 13 16:25:21 2013 telenc_r
*/

#include	<stdlib.h>
#include	<math.h>
#include	"wolf.h"

void	init_pos_player(t_wolf *wolf)
{
  if (wolf->play == NULL)
    {
      wolf->play = my_malloc(sizeof(t_player));
      wolf->play->num_game = 0;
      wolf->play->pos_player = NULL;
    }
  if (wolf->play->pos_player == NULL)
    wolf->play->pos_player = my_malloc(sizeof(t_f_point));
  wolf->play->pos_player->x = 0.5;
  wolf->play->pos_player->y = 0.5;
  verif_pos(wolf);
  wolf->play->deg_player = 0;
  wolf->play->sin_player = sin(RAD(wolf->play->deg_player));
  wolf->play->cos_player = cos(RAD(wolf->play->deg_player));
  wolf->play->max_tok = 0;
  wolf->play->nb_tok = 0;
  wolf->play->num_game += 1;
}

void	change_deg(t_wolf *wolf, int deg)
{
  wolf->play->deg_player += deg;
  wolf->play->sin_player = sin(RAD(wolf->play->deg_player));
  wolf->play->cos_player = cos(RAD(wolf->play->deg_player));
  init_image(wolf);
}

void	change_wall_is_seen(t_wolf *wolf)
{
  int	x;
  int	y;

  x = (int)(wolf->play->pos_player->x);
  y = (int)(wolf->play->pos_player->y);
  wolf->map[x + (y * wolf->size_line_map)]->is_seen = 1;
  if (x + 1 < wolf->size_map)
    wolf->map[(x + 1) + (y * wolf->size_line_map)]->is_seen = 1;
  if (x-1 >= 0)
    wolf->map[(x - 1) + (y * wolf->size_line_map)]->is_seen = 1;
  if (y-1 >= 0)
    wolf->map[x + ((y - 1) * wolf->size_line_map)]->is_seen = 1;
  if (y + 1 < wolf->size_line_map)
    wolf->map[x + ((y + 1) * wolf->size_line_map)]->is_seen = 1;
  if (y - 1 >= 0 && x - 1 >= 0)
    wolf->map[(x - 1) + ((y - 1) * wolf->size_line_map)]->is_seen = 1;
  if (y-1 >= 0 && x + 1 < wolf->size_map)
    wolf->map[(x + 1) + ((y - 1) * wolf->size_line_map)]->is_seen = 1;
  if (y + 1 < wolf->size_line_map && x - 1 >= 0)
    wolf->map[x - 1 + ((y + 1) * wolf->size_line_map)]->is_seen = 1;
  if (y + 1 < wolf->size_line_map && x + 1 < wolf->size_map)
    wolf->map[x + 1 + ((y + 1) * wolf->size_line_map)]->is_seen = 1;
}

void	change_pos_up(t_wolf *wolf)
{
  t_f_point	*vector_directory;

  vector_directory = get_vector_directory(wolf, WIDTH / 2);
  wolf->play->pos_player->x += vector_directory->x * SPEED;
  wolf->play->pos_player->y += vector_directory->y * SPEED;
  if (is_wall((int)wolf->play->pos_player->x,
	      (int)wolf->play->pos_player->y, wolf, 1))
    {
      wolf->play->pos_player->x -= vector_directory->x * SPEED;
      wolf->play->pos_player->y -= vector_directory->y * SPEED;
    }
  else
    check_object(wolf);
  free(vector_directory);
  change_wall_is_seen(wolf);
}

void	change_pos_down(t_wolf *wolf)
{
  t_f_point	*vector_directory;

  vector_directory = get_vector_directory(wolf, WIDTH / 2);
  wolf->play->pos_player->x -= vector_directory->x * SPEED;
  wolf->play->pos_player->y -= vector_directory->y * SPEED;
  if (is_wall((int)wolf->play->pos_player->x,
	      (int)wolf->play->pos_player->y, wolf, 1))
    {
      wolf->play->pos_player->x += vector_directory->x * SPEED;
      wolf->play->pos_player->y += vector_directory->y * SPEED;
    }
  else
    check_object(wolf);
  free(vector_directory);
  change_wall_is_seen(wolf);
}
