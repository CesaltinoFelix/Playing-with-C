#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *prev;
	struct s_node *next;
}	t_list;

typedef struct s_init {
char	**arguments;
t_list	*stack_a;
t_list	*stack_b;
int	num_args;
int	num_values_a;
int	num_values_b;
}	t_init;

//################## TENHO QUE APAGAR ######################################
void ft_print_stack(t_list *stack);
//################## TENHO QUE APAGAR ######################################

//UTILS FUCTIONS
int	ft_count_words(char **arguments);
int	ft_get_max_value(t_list *stack);
int	ft_get_min_value(t_list *stack);
//HELPERS FUNCTIONS
void	push(t_list **stack, int value);
void	create_stacks(t_init *ps);
//ERROR FUNCTION
void	cleanup_and_error(t_init *ps);
int	error(void);
//CHECK FUNCTIONS
void	ft_check_is_num(t_init *ps, char *str);
void	ft_check_max_min(t_init *ps, char *str);
void	check_doubles(t_init *ps);
int	check_order(t_list *stack);
//FREE FUNCTIONS
void	ft_free_matrix(char **matrix);
void free_stacks(t_init *ps);
//ALGORITHMS
void	algorithms(t_init *ps);
void	two_args_alg(t_init *ps);
void	three_args_alg(t_init *ps);
//SWAP FUNCTIONS
void	ft_swap_a(t_init *ps, int is_comb_operatin);
void	ft_swap_b(t_init *ps, int is_comb_operatin);
void	ft_swap_swap(t_init *ps);
//ROTATE FUNCTION
void	ft_rotate_a(t_init *ps, int is_comb_operation);
void	ft_rotate_b(t_init *ps, int is_comb_operation);
void	ft_reverse_rotate(t_init *ps);
void	ft_reverse_rotate_a(t_init *ps, int is_comb_operation);
void	ft_reverse_rotate_b(t_init *ps, int is_comb_operation);
void	ft_reverse_rotate_rotate(t_init *ps);
#endif