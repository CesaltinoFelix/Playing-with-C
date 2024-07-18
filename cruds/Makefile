# Nome do programa
PROGRAM = crud00

# Diretório da libft
LIBFT_DIR = ./libft_update

VALGRIND = valgrind --leak-check=yes
# Biblioteca e cabeçalhos
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Arquivos fonte e objetos do programa
SRCS = crud00.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PROGRAM)

# Compila a libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compila o programa
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES) -o $(PROGRAM)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: all
	$(VALGRIND) ./$(PROGRAM)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re run
