##
## Makefile for bistromathique in /home/telenc_r/Bistromathique
## 
## Made by telenc_r
## Login   <telenc_r@epitech.net>
## 
## Started on  Wed Oct 31 10:12:45 2012 telenc_r
## Last update Sun Jan 13 17:41:23 2013 telenc_r
##

CC	= cc -g

FLAGS	= -pipe

#CFLAGS	+= -Wextra -Wall
#CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I includes/

LDFLAGS	= 

RM	= rm -fr

NAME	= wolf3d

SRC	=main.c \
	create_map.c \
	error.c \
	verif.c \
	player.c \
	fenetre.c \
	draw_line.c \
	draw_line_wall.c \
	wall.c \
	calc.c \
	calc2.c \
	str.c \
	keycode.c \
	struct.c \
	object.c \
	mini_map.c \
	keyboard.c \
	menu.c \
	magie.c \
	screen_game.c \
	lib/get_next_line.c \
	lib/my_putchar.c \
	lib/my_putstr.c \
	lib/my_strcat.c \
	lib/my_strlen.c \
	lib/malloc.c \
	lib/my_put_pixel.c \
	lib/my_put_pixel_two.c \
	lib/my_getnbr.c	\
	lib/my_nbr_to_char.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g -lmlx -lXext -lX11 -lm
clean:
	$(RM) $(OBJ);

fclean:	clean
	$(RM) $(NAME)

re:	fclean all