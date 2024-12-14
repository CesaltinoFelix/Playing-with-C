/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:47:18 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/02 12:57:55 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_b_in_a(t_init *ps, t_target target_data)
{
	if (target_data.a_direction == target_data.b_direction)
	{
		ft_rrr_rr(ps, target_data);
	}
	while (ps->stack_b->value != target_data.b_value)
	{
		if (target_data.b_direction == -1)
			ft_rotate_b(ps, 0);
		else if (target_data.b_direction == 1)
			ft_reverse_rotate_b(ps, 0);
	}
	while (ps->stack_a->value != target_data.a_value)
	{
		if (target_data.a_direction == -1)
			ft_rotate_a(ps, 0);
		else if (target_data.a_direction == 1)
			ft_reverse_rotate_a(ps, 0);
	}
	ft_push_a(ps);
}

void	ft_set_targets(t_helper *vars, t_target *dados, t_init *ps)
{
	if (vars->stack_a + vars->stack_b < vars->best_target_b)
	{
		vars->best_target_b = vars->stack_a + vars->stack_b;
		dados->a_value = vars->value;
		dados->a_direction = vars->a_direction;
		dados->b_value = vars->arg;
		dados->b_direction = vars->b_direction;
	}
	if (ft_case_rrr_or_rr(vars->arg, ps, 1) < vars->best_target_b)
	{
		vars->best_target_b = ft_case_rrr_or_rr(vars->arg, ps, 1);
		dados->a_value = vars->value;
		dados->a_direction = 1;
		dados->b_value = vars->arg;
		dados->b_direction = 1;
	}
	if (ft_case_rrr_or_rr(vars->arg, ps, -1) < vars->best_target_b)
	{
		vars->best_target_b = ft_case_rrr_or_rr(vars->arg, ps, -1);
		dados->a_value = vars->value;
		dados->a_direction = -1;
		dados->b_value = vars->arg;
		dados->b_direction = -1;
	}
}

void	ft_rrr_rr(t_init *ps, t_target data_target)
{
	while (((ps->stack_b->value != data_target.b_value)
			&& (ps->stack_a->value != data_target.a_value)))
	{
		if (data_target.b_direction == -1)
			ft_rotate_rotate(ps);
		else
			ft_reverse_rotate_rotate(ps);
	}
}

int	ft_case_rrr_or_rr(int value, t_init *ps, int direction)
{
	int	target;
	int	n_opt;

	if (direction == -1)
	{
		target = ft_get_best_option(ps->stack_a, value);
		n_opt = ft_get_index(ps->stack_b, value);
		if (ft_get_index(ps->stack_a, target) > n_opt)
			n_opt = ft_get_index(ps->stack_a, target);
	}
	if (direction == 1)
	{
		target = ft_get_best_option(ps->stack_a, value);
		n_opt = ps->num_values_b - ft_get_index(ps->stack_b, value);
		if (ps->num_values_b - ft_get_index(ps->stack_a, target) > n_opt)
			n_opt = ps->num_values_a - ft_get_index(ps->stack_a, target);
	}
	return (n_opt + 1);
}