/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:53:59 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/26 14:31:27 by cefelix          ###   ########.fr       */
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

// Function to push a value onto the stack
void push(t_list **stack, int value) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) {
        error(); // Handle memory allocation failure
        return;
    }
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Function to create stacks from parsed arguments
void create_stacks(t_init *ps) {
    int i = 0;
    while (i < ps->num_args) {
        int value = ft_atoi(ps->arguments[i]); // Convert string to integer
        push(&ps->stack_a, value); // Push value onto stack_a
        i++;
    }
}

// Function to handle input and initialize stacks
static int get_two_args(t_init *ps, char **argv) {
    ps->arguments = ft_split(argv[1], ' ');
    ps->num_args = ft_count_words(ps->arguments);
    ps->has_matrix_arguments = 1;

    if (!ps->arguments) {
        return error(); // Handle error
    }

    int i = 0;
    while (i < ps->num_args) {
        ft_check_is_num(ps->arguments, ps->arguments[i]);
        check_max_min(ps, ps->arguments[i]); // Assuming you have this function
        i++;
    }

    create_stacks(ps); // Call the stack creation function

    // Free the split arguments after using them
    ft_free_matrix(ps->arguments);
    return 1;
}

int main(int argc, char *argv[])
{
    t_init ps;

    ps.num_values_a = 0;
    ps.arguments = NULL;
    ps.has_matrix_arguments = 0;
    
    if (argc == 1)
        return 0;

    ps.stack_a = NULL;
    ps.stack_b = NULL;

    if (argc == 2)
    {
        if (!get_two_args(&ps, argv))
            return 0;	
    }

    // Print stack to verify values
    ft_print_stack(ps.stack_a);
    
    // Free allocated memory for stack_a if necessary
    // Implement a function to clear the stack if needed
    
    return 0;
}
