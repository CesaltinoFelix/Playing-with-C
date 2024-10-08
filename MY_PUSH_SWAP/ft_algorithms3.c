/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithms3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:10 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 11:30:50 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_rr(t_node **a, t_node **b, t_target target_data)
{
	while ((((*b)->value != target_data.value_b)
			&& ((*a)->value != target_data.value_a)))
	{
		if (target_data.dir_b == -1)
			ft_rotate_rotate(a, b);
		else
			ft_reverse_rotate_rotate(a, b);
	}
}

int	ft_case_rrr_or_rr(int value, t_node **a, t_node **b, int direction)
{
	int	target;
	int	opt_moves;

	if (direction == -1)
	{
		target = ft_get_best_option(a, value);
		opt_moves = ft_get_index(*b, value);
		if (ft_get_index(*a, target) > opt_moves)
			opt_moves = ft_get_index(*a, target);
	}
	if (direction == 1)
	{
		target = ft_get_best_option(a, value);
		opt_moves = ft_count_elem(*b) - ft_get_index(*b, value);
		if (ft_count_elem(*a) - ft_get_index(*a, target) > opt_moves)
			opt_moves = ft_count_elem(*a) - ft_get_index(*a, target);
	}
	return (opt_moves + 1);
}

void	ft_set_targets(t_s_info *vars, t_target *target_data,
	t_node **a, t_node **b)
{
	if (vars->stack_a_size + vars->stack_b_size < vars->total_moves)
	{
		vars->total_moves = vars->stack_a_size + vars->stack_b_size;
		target_data->value_a = vars->element_value;
		target_data->dir_a = vars->dir_a;
		target_data->value_b = vars->arg_value;
		target_data->dir_b = vars->dir_b;
	}
	if (ft_case_rrr_or_rr(vars->arg_value, a, b, 1) < vars->total_moves)
	{
		vars->total_moves = ft_case_rrr_or_rr(vars->arg_value, a, b, 1);
		target_data->value_a = vars->element_value;
		target_data->dir_a = 1;
		target_data->value_b = vars->arg_value;
		target_data->dir_b = 1;
	}
	if (ft_case_rrr_or_rr(vars->arg_value, a, b, -1) < vars->total_moves)
	{
		vars->total_moves = ft_case_rrr_or_rr(vars->arg_value, a, b, -1);
		target_data->value_a = vars->element_value;
		target_data->dir_a = -1;
		target_data->value_b = vars->arg_value;
		target_data->dir_b = -1;
	}
}

void	ft_set_directions(t_node **a, t_node **b, t_s_info *vars)
{
	if (vars->element_index <= ft_count_elem(*a) / 2)
	{
		vars->stack_a_size = vars->element_index;
		vars->dir_a = -1;
	}
	else if (vars->element_index > ft_count_elem(*a) / 2)
	{
		vars->stack_a_size = ft_count_elem(*a) - vars->element_index;
		vars->dir_a = 1;
	}
	if (vars->counter <= ft_count_elem(*b) / 2)
	{
		vars->stack_b_size = vars->counter + 1;
		vars->dir_b = -1;
	}
	else if (vars->counter > ft_count_elem(*b) / 2)
	{
		vars->stack_b_size = ft_count_elem(*b) - vars->counter + 1;
		vars->dir_b = 1;
	}
}

t_target	ft_calculate_moves(t_node **a, t_node **b)
{
	t_node		*tmp;
	t_s_info	vars;
	t_target	target_data;

	vars.counter = 0;
	vars.total_moves = INT_MAX;
	tmp = (*b);
	while (tmp)
	{
		vars.element_value = ft_get_best_option(a, tmp->value);
		vars.element_index = ft_get_index(*a, vars.element_value);
		ft_set_directions(a, b, &vars);
		vars.arg_value = tmp->value;
		ft_set_targets(&vars, &target_data, a, b);
		tmp = tmp->next;
		vars.counter++;
	}
	return (target_data);
}
