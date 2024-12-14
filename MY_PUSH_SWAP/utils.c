/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:53:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 14:22:58 by cefelix          ###   ########.fr       */
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