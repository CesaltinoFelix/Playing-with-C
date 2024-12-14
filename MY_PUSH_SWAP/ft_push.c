/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:20 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/08 13:18:52 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_node **a, t_node **b)
{
	t_node	*top;

	if (*b == NULL)
		return ;
	top = ft_stack_get_top(*b);
	*b = (*b)->next;
	top->next = *a;
	*a = top;
	ft_printf("pa\n");
}

void	ft_push_b(t_node **a, t_node **b)
{
	t_node	*top;

	if (*a == NULL)
		return ;
	top = ft_stack_get_top(*a);
	*a = (*a)->next;
	top->next = *b;
	*b = top;
	ft_printf("pb\n");
}
