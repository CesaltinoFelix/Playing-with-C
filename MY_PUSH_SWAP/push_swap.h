#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
}	t_list;

typedef struct s_init {
char	**arguments;
t_list	*stack_a;
t_list	*stack_b;
int	num_args;
int	num_values_a;
int	num_values_b;
int	has_matrix_arguments;
}	t_init;

//UTILS FUCTIONS
void	ft_check_is_num(char **arguments, char *str);
int	ft_count_words(char **arguments);
void	ft_free_matrix(char **matrix);

//HELPERS FUNCTIONS
void	create_stack(t_init *ps);
int	stack_size(t_list *list);
int	is_empty(t_list *list);

//ERROR FUNCTION
int	error(void);
#endif