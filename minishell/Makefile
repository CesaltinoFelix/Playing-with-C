NAME = minishell
CC = cc

CFLAGS = -Wall -Werror -Wextra -lreadline -lhistory -Iincludes

DIR_LIBFT = libft
DIR_PRINTF = libft/printf

LIBFT = $(DIR_LIBFT)/libft.a

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
		$(CC)  $(OBJ) -L$(DIR_LIBFT) -lft -L$(DIR_PRINTF) -lftprintf -o $(NAME) $(CFLAGS) 


$(LIBFT): 
	$(MAKE) -C $(DIR_LIBFT)

clean: 
	$(MAKE) clean -C $(DIR_LIBFT)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(DIR_LIBFT)
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./minishell

.PHONY: all clean fclean re run