/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:53:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/03 12:20:51 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_words(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
		i++;
	return (i);
}

int	ft_get_max_value(t_list *stack)
{
	int	tmp;

	tmp = stack->value;
	while (stack)
	{
		if (stack->value > tmp)
			tmp = stack->value;
		stack = stack->next;
	}
	return (tmp);
}

int	ft_get_min_value(t_list *stack)
{
	int	tmp;
	int	max;

	max = ft_get_max_value(stack);
	tmp = max;
	while (stack)
	{
		if (!(stack->value > tmp))
			tmp = stack->value;
		stack = stack->next;
	}
	return (tmp);
}

// t_target	ft_get_best_comb(t_init *ps)
// {
// 	t_list	*tmp;
// 	t_target	target;
// 	t_helper	vars;

// 	vars.i = 0;
// 	vars.best_target_b = INT_MAX;
// 	tmp = ps->stack_b;
// 	while ((tmp))
// 	{
// 		vars.value = ft_get_best_option(ps->stack_a, tmp->value);
// 		vars.index = ft_get_index(ps->stack_a, vars.value);
// 		ft_set_direction(ps, &vars);
// 		vars.arg = tmp->value;
// 		ft_set_targets(&vars, &target, ps);
// 		tmp = tmp->next;
// 		vars.i++;
// 	}
// 	ft_printf("BEST = %d, index = %d VB = %d\n", vars.value, vars.index, vars.best_target_b);
// 	return (target);
// }