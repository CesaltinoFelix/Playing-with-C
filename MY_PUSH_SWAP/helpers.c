/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:06 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/26 14:29:04 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack, int value) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) {
        error(); // handle memory allocation failure
        return;
    }
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

void	create_stacks(t_init *ps) {
    for (int i = 0; i < ps->num_args; i++) {
        int value = ft_atoi(ps->arguments[i]); // Convert string to integer
        push(&ps->stack_a, value); // Push value onto stack_a
    }
}
