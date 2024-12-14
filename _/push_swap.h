#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

# define INT_MIN -2147483648

# define INT_MAX 2147483647

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
}	t_init;

typedef struct s_target
{
	int				a_value;
	int				b_value;
	int				a_direction;
	int				b_direction;
}	t_target;

typedef struct s_helper
{
	long int		best_target_b;
	int				stack_a;
	int				stack_b;
	int				a_direction;
	int				b_direction;
	int				index;
	int				value;
	int				i;
	int				arg;
}					t_helper;





int		ft_find_best_position_in_a(t_init *ps, int value_b);
int		ft_calculate_cost(t_init *ps, int pos_a, int pos_b);
int		ft_get_direction(int stack_size, int position);
t_target	ft_get_best_comb(t_init *ps);
void	ft_put_min_top(t_init *ps, t_list *stack, int size);
void	ft_order_b_in_a(t_init *ps, t_target target_data);
int		ft_get_index(t_list *stack, int value); //para tudo aqui























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
void	big_algorithm(t_init *ps);
//SWAP FUNCTIONS
void	ft_swap_a(t_init *ps, int is_comb_operatin);
void	ft_swap_b(t_init *ps, int is_comb_operatin);
void	ft_swap_swap(t_init *ps);
//ROTATE FUNCTION
void	ft_rotate_a(t_init *ps, int is_comb_operation);
void	ft_rotate_b(t_init *ps, int is_comb_operation);
void	ft_rotate_rotate(t_init *ps);
void	ft_reverse_rotate_a(t_init *ps, int is_comb_operation);
void	ft_reverse_rotate_b(t_init *ps, int is_comb_operation);
void	ft_reverse_rotate_rotate(t_init *ps);
//push functions 
void	ft_push_a(t_init *ps);
void	ft_push_b(t_init *ps);
#endif