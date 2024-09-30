/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:47:41 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 14:28:13 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_init *ps, int is_comb_operation)
{
	t_list *stack_a;
	int temp;
	stack_a = ps->stack_a;
	if(ps->num_values_a > 1)
	{
		temp = stack_a->value;
		while (stack_a->next)
		{
			stack_a->value = stack_a->next->value;
			stack_a = stack_a->next;
		}
		stack_a->value = temp;
		if(!is_comb_operation)
			ft_printf("ra\n");
	}
}

void	ft_rotate_b(t_init *ps, int is_comb_operation)
{
	t_list *stack_b;
	int temp;
	stack_b = ps->stack_b;
	if(ps->num_values_a > 1)
	{
		temp = stack_b->value;
		while (stack_b->next)
		{
			stack_b->value = stack_b->next->value;
			stack_b = stack_b->next;
		}
		stack_b->value = temp;
		if(!is_comb_operation)
			ft_printf("rb\n");
	}
}

void	ft_reverse_rotate(t_init *ps)
{
	ft_rotate_a(ps, 1);
	ft_rotate_b(ps, 1);
	ft_printf("rr\n");
}