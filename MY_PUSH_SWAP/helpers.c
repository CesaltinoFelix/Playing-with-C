/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:06 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/27 09:10:40 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to push a value onto the stack
void    push(t_list **stack, int value) {
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
void    create_stacks(t_init *ps) 
{
    int i = 0;
    while (i < ps->num_args) {
        int value = ft_atoi(ps->arguments[i]); // Convert string to integer
        push(&ps->stack_a, value); // Push value onto stack_a
        i++;
    }
}
