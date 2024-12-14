/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:50:08 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/04 10:58:46 by cefelix          ###   ########.fr       */
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
		target_data = ft_get_best_comb(ps);
		if(ps->stack_b->value > ft_get_max_value(ps->stack_a) || ps->stack_b->value < ft_get_min_value(ps->stack_a))
		{
			ft_put_min_top(ps, ps->stack_a, ps->num_values_a);
			ft_push_a(ps);

		}
		else
			ft_order_b_in_a(ps, target_data);
	}
	int i = 0;
	while (!check_order(ps->stack_a))
	{
			if (i == 20 )
			{
				printf("elementos em A = %d", ps->num_values_a);
				break;
			}
	int max_value = ft_get_max_value(ps->stack_a);
	int index_max = ft_get_index(ps->stack_a, max_value);

	if (index_max <= ps->num_values_a / 2)
		ft_rotate_a(ps, 0);
	else
		ft_reverse_rotate_a(ps, 0);

	i++;
	}

}