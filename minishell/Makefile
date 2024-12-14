NAME = minishell
CC = cc

CFLAGS = -Wall -Werror -Wextra -lreadline -lhistory

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
		$(CC)  $(OBJ) -o $(NAME) $(CFLAGS)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./minishell

.PHONY: all clean fclean re run