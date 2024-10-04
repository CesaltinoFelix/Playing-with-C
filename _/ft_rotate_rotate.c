/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:47:41 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/04 10:44:56 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_reverse_rotate_a(t_init *ps, int is_comb_operation) {
    t_list *last;
    t_list *second_last;

    if (!ps->stack_a || ps->num_values_a < 2)
        return;

    // Encontra o último e o penúltimo nós
    last = ps->stack_a;
    while (last->next) {
        last = last->next;
    }

    second_last = ps->stack_a;
    while (second_last->next != last) {
        second_last = second_last->next;
    }

    // Ajusta os ponteiros
    second_last->next = NULL;  // O penúltimo se torna o novo final da lista
    last->next = ps->stack_a;   // O último nó agora aponta para o antigo topo
    ps->stack_a = last;         // Atualiza o topo da pilha

    // Debugging prints
    if (!is_comb_operation) {
        printf("After reverse rotation, stack A: \n");
        ft_print_stack(ps->stack_a); // Supondo que você tenha uma função para imprimir a pilha
        ft_printf("rra\n");
    }
}



void ft_reverse_rotate_b(t_init *ps, int is_comb_operation) {
    t_list *last;
    t_list *second_last;

    if (!ps->stack_b || ps->num_values_b < 2)  // Corrigido para verificar num_values_b
        return;

    // Encontra o último e o penúltimo nós
    last = ps->stack_b;
    while (last->next) {
        last = last->next;
    }

    second_last = ps->stack_b;
    while (second_last->next != last) {
        second_last = second_last->next;
    }

    // Ajusta os ponteiros
    second_last->next = NULL;  // O penúltimo se torna o novo final da lista
    last->next = ps->stack_b;   // O último nó agora aponta para o antigo topo
    ps->stack_b = last;         // Atualiza o topo da pilha

    if (!is_comb_operation)
        ft_printf("rrb\n");
}


void	ft_reverse_rotate_rotate(t_init *ps)
{
	ft_reverse_rotate_a(ps, 1);
	ft_reverse_rotate_b(ps, 1);
	ft_printf("rrr\n");
}