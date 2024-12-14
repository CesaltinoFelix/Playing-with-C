/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:48:50 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/03 11:52:12 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_init *ps)
{
    t_list *temp;

    if (!ps->stack_a)  // Verifica se a pilha A não está vazia
        return;

    // Remove o topo da pilha A
    temp = ps->stack_a;
    ps->stack_a = ps->stack_a->next;

    // Adiciona o nó removido ao topo da pilha B
    temp->next = ps->stack_b;
    ps->stack_b = temp;

    // Atualiza os contadores de elementos
    ps->num_values_a--;
    ps->num_values_b++;

    // Exibe a operação, se necessário
    ft_printf("pb\n");
}

void	ft_push_a(t_init *ps)
{
    t_list *temp;

    if (!ps->stack_b)  // Verifica se a pilha B não está vazia
        return;

    // Remove o topo da pilha B
    temp = ps->stack_b;
    ps->stack_b = ps->stack_b->next;

    // Adiciona o nó removido ao topo da pilha A
    temp->next = ps->stack_a;
    ps->stack_a = temp;

    // Atualiza os contadores de elementos
    ps->num_values_b--;
    ps->num_values_a++;

    // Exibe a operação, se necessário
    ft_printf("pa\n");
}
