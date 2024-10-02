/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:47:18 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/02 12:13:41 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_b_in_a(t_init *ps, t_target target_data)
{
	if (target_data.a_direction == target_data.b_direction)
	{
		ft_rrr_rr(ps->stack_a, ps->stack_b, target_data);
	}
	while (ps->stack_b->value != target_data.b_value)
	{
		if (target_data.b_direction == -1)
			ft_rotate_b(ps->stack_b, 0);
		else if (target_data.b_direction == 1)
			ft_reverse_rotate_b(ps->stack_b, 1);
	}
	while (ps->stack_a->value != target_data.a_value)
	{
		if (target_data.a_direction == -1)
			ft_rotate_a(ps->stack_a, 0);
		else if (target_data.a_direction == 1)
			ft_reverse_rotate_a(ps->stack_a, 1);
	}
	ft_push_a(ps);
}