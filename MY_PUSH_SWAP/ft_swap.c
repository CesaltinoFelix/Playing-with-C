/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:28 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/06 15:09:13 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_node **a, int flg)
{
	t_node	*link1;
	t_node	*link2;
	t_node	*link3;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	link1 = (*a);
	link2 = link1->next;
	link3 = link2->next;
	link2->next = link1;
	link1->next = link3;
	*a = link2;
	if (flg == 1)
		ft_printf("sa\n");
}

void	ft_swap_b(t_node **b, int flg)
{
	t_node	*link1;
	t_node	*link2;
	t_node	*link3;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	link1 = (*b);
	link2 = link1->next;
	link3 = link2->next;
	link2->next = link1;
	link1->next = link3;
	*b = link2;
	if (flg == 1)
		ft_printf("sb\n");
}

void	ft_swap_swap(t_node **a, t_node **b)
{
	ft_swap_a(a, 0);
	ft_swap_b(b, 0);
	ft_printf("ss\n");
}
