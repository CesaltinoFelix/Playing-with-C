/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:53:59 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 14:41:42 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to print the stack
void ft_print_stack(t_list *stack)
{	
	t_list *temp = stack;

	while (temp != NULL)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
}



// Function to handle two args input and initialize stacks
static int  get_two_args(t_init *ps, char **argv) {
    ps->arguments = ft_split(argv[1], ' ');
    ps->num_args = ft_count_words(ps->arguments);

    if (!ps->arguments || ps->num_args == 0) {
    ft_free_matrix(ps->arguments);
    return error();
    }

    int i = 0;
    while (i < ps->num_args) {
        ft_check_is_num(ps, ps->arguments[i]);
        ft_check_max_min(ps, ps->arguments[i]);
        i++;
    }

    create_stacks(ps);
    
    ft_free_matrix(ps->arguments);
    return 1;
}

// Function to handle mult args input and initialize stacks
static int  get_mult_args(t_init *ps, char **argv, int argc) {
    ps->num_args = argc -1;
    ps->arguments = NULL;
    int i;

    i = ps->num_args;
    while (i-- > 0)
    {
        ft_check_is_num(ps, argv[i + 1]);
        ft_check_max_min(ps, argv[i + 1]);
        push(&ps->stack_a, ft_atoi(argv[i + 1]));
        ps->num_values_a++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    t_init ps;

    ps.num_values_a = 0;
    ps.num_values_b = 0;
    ps.arguments = NULL;
    
    if (argc == 1)
        return 0;

    ps.stack_a = NULL;
    ps.stack_b = NULL;

    if (argc == 2)
    {
        if (!get_two_args(&ps, argv))
            return 0;	
    }
    else
    {
        if(!get_mult_args(&ps, argv, argc))
            return 0;
    }
    check_doubles(&ps);
    if (check_order(ps.stack_a))
			free_stacks(&ps);
    else
    algorithms(&ps);
    free_stacks(&ps);
    
    return 0;
}
