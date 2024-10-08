/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:24 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/06 15:09:13 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_node **a, int flg)
{
	t_node	*top;
	t_node	*base;

	if (*a == NULL)
		return ;
	top = ft_stack_get_top(*a);
	base = ft_stack_get_last(*a);
	*a = (*a)->next;
	base->next = top;
	top->next = NULL;
	if (flg == 1)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_node **b, int flg)
{
	t_node	*top;
	t_node	*base;

	if (*b == NULL)
		return ;
	top = ft_stack_get_top(*b);
	base = ft_stack_get_last(*b);
	*b = (*b)->next;
	base->next = top;
	top->next = NULL;
	if (flg == 1)
		ft_printf("rb\n");
}

void	ft_reverse_rotate_a(t_node **a, int flg)
{
	t_node	*top;
	t_node	*base;

	if (*a == NULL)
		return ;
	top = ft_stack_get_top(*a);
	base = ft_stack_get_last(*a);
	while (top->next != base)
		top = top->next;
	top->next = NULL;
	base->next = *a;
	*a = base;
	if (flg == 1)
		ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_node **b, int flg)
{
	t_node	*top;
	t_node	*base;

	if (*b == NULL)
		return ;
	top = ft_stack_get_top(*b);
	base = ft_stack_get_last(*b);
	while (top->next != base)
		top = top->next;
	top->next = NULL;
	base->next = *b;
	*b = base;
	if (flg == 1)
		ft_printf("rrb\n");
}
