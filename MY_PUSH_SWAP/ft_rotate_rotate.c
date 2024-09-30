/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:47:41 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 14:29:26 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_init *ps, int is_comb_operation)
{
	t_list	*last;
	t_list	*second_last;

	if (!ps->stack_a || ps->num_values_a < 2)
		return;

	last = ps->stack_a;
	while (last->next)
		last = last->next;

	second_last = last->prev;
	second_last->next = NULL;

	last->prev = NULL;
	last->next = ps->stack_a;
	ps->stack_a->prev = last;
	ps->stack_a = last;

	if (!is_comb_operation)
		ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_init *ps, int is_comb_operation)
{
	t_list	*last;
	t_list	*second_last;

	if (!ps->stack_b || ps->num_values_a < 2)
		return;

	last = ps->stack_b;
	while (last->next)
		last = last->next;

	second_last = last->prev;
	second_last->next = NULL;

	last->prev = NULL;
	last->next = ps->stack_b;
	ps->stack_b->prev = last;
	ps->stack_b = last;

	if (!is_comb_operation)
		ft_printf("rrb\n");
}

void	ft_reverse_rotate_rotate(t_init *ps)
{
	ft_reverse_rotate_a(ps, 1);
	ft_reverse_rotate_b(ps, 1);
	ft_printf("rrr\n");
}