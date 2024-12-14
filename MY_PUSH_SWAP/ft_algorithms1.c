/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:14:56 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 11:23:19 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_args_alg(t_node **a)
{
	if (!ft_check_sorted(*a))
		ft_swap_a(a, 1);
}

void	three_args_alg(t_node **a)
{
	if (ft_stack_get_min(*a) == (*a)->value)
	{
		ft_reverse_rotate_a(a, 1);
		ft_swap_a(a, 1);
	}
	else if (ft_stack_get_max(*a) == (*a)->value)
	{
		ft_rotate_a(a, 1);
		if (!ft_check_sorted(*a))
			ft_swap_a(a, 1);
	}
	else
	{
		if (ft_stack_get_min(*a) == (*a)->next->value)
			ft_swap_a(a, 1);
		else
			ft_reverse_rotate_a(a, 1);
	}
}
