/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:06 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 13:10:34 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_list **stack, int value) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) {
        error();
        return;
    }
    new_node->value = value;
    new_node->next = *stack;
    new_node->prev = NULL;
    
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void    create_stacks(t_init *ps) 
{
    int i;
    
    i = ps->num_args;
   while (i-- > 0)
   {
        int value = ft_atoi(ps->arguments[i]);
        push(&ps->stack_a, value);
        ps->num_values_a++;
    }
}
