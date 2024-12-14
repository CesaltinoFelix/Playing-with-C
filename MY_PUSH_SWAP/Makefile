SRCS	= main.c ft_utils.c ft_utils2.c ft_utils3.c ft_checks.c ft_checks2.c ft_algorithms1.c ft_algorithms2.c  ft_algorithms3.c ft_swap.c ft_rotate.c ft_push.c

SRC_DIR = sources/
OBJS	:= $(SRCS:%.c=%.o)
SRC = $(addprefix $(SRC_DIR), $(SRCS))

NAME	= push_swap

CC		= gcc -g
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror -g

all:		${NAME}

%.o:	$(SRC_DIR)%.c
		${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@

${NAME}:	${OBJS}
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} $^ -Llibft -lft -Lprintf -lftprintf -o ${NAME}

libft:
		make -C libft

printf:
		make -C printf

clean:
			make clean -C libft
			make clean -C printf
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re libft printf
