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
void	ft_check_is_num(t_init *ps, char *str);
int	ft_count_words(char **arguments);

//HELPERS FUNCTIONS
void	push(t_list **stack, int value);
void	create_stacks(t_init *ps);
//ERROR FUNCTION
void	cleanup_and_error(t_init *ps);
int	error(void);
//CHECK FUNCTIONS
void	ft_check_max_min(t_init *ps, char *str);
//FREE FUNCTIONS
void	ft_free_matrix(char **matrix);
void free_stacks(t_init *ps);
#endif