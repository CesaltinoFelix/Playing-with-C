# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 11:36:47 by cefelix           #+#    #+#              #
#    Updated: 2024/11/01 11:46:51 by cefelix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iprintf -Ilibft
MLX = -Lminilibx-linux -lmlx_Linux -L/usr/lib/X11 -lXext -lX11

LIB_DIR = ./printf
LIB_DIR1 = ./libft
LIB_DIR2 = ./minilibx-linux

PRINTF = $(LIB_DIR)/libftprintf.a
LIBFT = $(LIB_DIR1)/libft.a
MINILIBX = $(LIB_DIR2)/libmlx_Linux.a

SRC = src/main.c src/game0.c src/game1.c src/render.c src/utils.c src/utils1.c src/free_game.c src/validate_map.c src/assets.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -L$(LIB_DIR) -lftprintf -L$(LIB_DIR1) -lft -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(LIB_DIR)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR1)

$(MINILIBX):
	$(MAKE) -C $(LIB_DIR2)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(LIB_DIR1)
	$(MAKE) clean -C $(LIB_DIR2)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
