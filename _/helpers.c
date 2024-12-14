/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:46:06 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/03 11:53:11 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **stack, int value) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) {
        error();
        return;
    }
    new_node->value = value;      // Define o valor do novo nó
    new_node->next = *stack;      // O próximo nó do novo nó será o atual topo da pilha
    
    *stack = new_node;            // Atualiza o topo da pilha para o novo nó
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
