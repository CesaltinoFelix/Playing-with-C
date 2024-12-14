/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:35 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 11:30:50 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_get_max(t_node *list)
{
	int	tmp;

	if (!list)
		return (INT_MIN);
	tmp = list->value;
	while (list)
	{
		if (list->value > tmp)
			tmp = list->value;
		list = list->next;
	}
	return (tmp);
}

int	ft_stack_get_min(t_node *list)
{
	int	tmp;
	int	max;

	if (!list)
		return (INT_MAX);
	max = ft_stack_get_max(list);
	tmp = max;
	while (list)
	{
		if (list->value < tmp)
			tmp = list->value;
		list = list->next;
	}
	return (tmp);
}

int	ft_count_elem(t_node *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	ft_check_sorted(t_node *list)
{
	int	tmp;

	if (!list)
		return (1);
	tmp = list->value;
	while (list)
	{
		if (list->value >= tmp)
			tmp = list->value;
		else
			return (0);
		list = list->next;
	}
	return (1);
}
