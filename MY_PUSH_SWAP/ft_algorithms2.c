/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:03 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 11:30:50 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_best_option(t_node **a, int b)
{
	long int	value;
	t_node		*tmp;

	value = INT_MAX;
	if (b > ft_stack_get_max(*a) || b < ft_stack_get_min(*a))
		return (ft_stack_get_min(*a));
	else
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->value > b)
			{
				if (tmp->value < value)
					value = tmp->value;
			}
			tmp = tmp->next;
		}
	}
	return (value);
}

int	ft_get_index(t_node *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_insert_b_into_a(t_node **a, t_node **b, t_target target_data)
{
	if (target_data.dir_a == target_data.dir_b)
	{
		ft_rrr_rr(a, b, target_data);
	}
	while ((*b)->value != target_data.value_b)
	{
		if (target_data.dir_b == -1)
			ft_rotate_b(b, 1);
		else if (target_data.dir_b == 1)
			ft_reverse_rotate_b(b, 1);
	}
	while ((*a)->value != target_data.value_a)
	{
		if (target_data.dir_a == -1)
			ft_rotate_a(a, 1);
		else if (target_data.dir_a == 1)
			ft_reverse_rotate_a(a, 1);
	}
	ft_push_a(a, b);
}

void	big_algorithm(t_node **a, t_node **b)
{
	t_target	target_data;

	while (ft_count_elem(*a) > 3)
		ft_push_b(a, b);
	if (!ft_check_sorted(*a))
		three_args_alg(a);
	while (ft_count_elem(*b) > 0)
	{
		target_data = ft_calculate_moves(a, b);
		if ((*b)->value > ft_stack_get_max(*a)
			|| (*b)->value < ft_stack_get_min(*a))
		{
			ft_move_min_to_top(a);
			ft_push_a(a, b);
		}
		else
			ft_insert_b_into_a(a, b, target_data);
	}
	while (!ft_check_sorted(*a))
	{
		if (ft_get_index(*a, ft_stack_get_max(*a)) <= ft_count_elem(*a) / 2)
			ft_rotate_a(a, 1);
		else
			ft_reverse_rotate_a(a, 1);
	}
}
