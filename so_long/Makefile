NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
MLX = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

SRC = src/main.c src/game.c src/render.c src/utils.c src/free_game.c src/validate_map.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

e:	re
	rm -f $(OBJ)
	valgrind ./so_long ./maps/map1.ber

.PHONY: all fclean re clean e