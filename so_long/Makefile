NAME = game
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
MLX = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRC = src/main.c src/game.c src/render.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
