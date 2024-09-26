# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefelix <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 17:19:52 by cefelix           #+#    #+#              #
#    Updated: 2024/06/16 17:19:56 by cefelix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC =  cc
RM = rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
SRCS = 	ft_abs.c\
		ft_printf.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putchar.c\
		ft_print_hex.c\
		ft_print_ptr.c\
		ft_putunsigned.c\
		
OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
		
all: ${NAME}
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
	
