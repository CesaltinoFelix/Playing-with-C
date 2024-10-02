/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:50:08 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/02 12:14:12 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_algorithm(t_init *ps)
{
	t_target	target_data;
	while (ps->num_values_a > 3)
		ft_push_b(ps);
	
	if(!check_order(ps->stack_a))
		three_args_alg(ps);
	while (ps->num_values_b > 0)
	{
		target_data = ft_get_best_comb(ps->stack_a, ps->stack_b);
		if(ps->stack_b->value > ft_get_max_value(ps->stack_a) || ps->stack_b->value < ft_get_min_value(ps->stack_a))
		{
			ft_put_min_top(ps->stack_a, ps->num_values_a);
			ft_push_a(ps);

		}
		else
			ft_order_b_in_a(ps, target_data);
	}
}