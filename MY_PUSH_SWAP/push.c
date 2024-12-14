/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:57:13 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/01 10:02:41 by cefelix          ###   ########.fr       */
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

    if (ps->stack_a)
        ps->stack_a->prev = NULL;

    // Adiciona o nó removido ao topo da pilha B
    temp->next = ps->stack_b;
    if (ps->stack_b)
        ps->stack_b->prev = temp;

    ps->stack_b = temp;
    ps->stack_b->prev = NULL;

    // Atualiza os contadores de elementos
    ps->num_values_a--;
    ps->num_values_b++;

    // Exibe a operação, se necessário
    ft_printf("pb\n");
}
void    ft_push_a(t_init *ps)
{
    t_list *temp;

    if (!ps->stack_b)  // Verifica se a pilha B não está vazia
        return;

    // Remove o topo da pilha B
    temp = ps->stack_b;
    ps->stack_b = ps->stack_b->next;

    if (ps->stack_b)
        ps->stack_b->prev = NULL;

    // Adiciona o nó removido ao topo da pilha A
    temp->next = ps->stack_a;
    if (ps->stack_a)
        ps->stack_a->prev = temp;

    ps->stack_a = temp;
    ps->stack_a->prev = NULL;

    // Atualiza os contadores de elementos
    ps->num_values_b--;
    ps->num_values_a++;

    // Exibe a operação, se necessário
    ft_printf("pa\n");
}
