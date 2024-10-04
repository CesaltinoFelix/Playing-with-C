/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:19:12 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 11:42:58 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_init *ps, int is_comb_operatin)
{	
	t_list	*stack_a;
	int	temp;

	if(ps->num_values_a > 1)
	{
		stack_a = ps->stack_a;
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
		if(!is_comb_operatin)
			ft_printf("sa\n");
	}

}

void	ft_swap_b(t_init *ps, int is_comb_operatin)
{	
	t_list	*stack_b;
	int	temp;

	if(ps->num_values_a > 1)
	{
		stack_b = ps->stack_b;
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
		if(!is_comb_operatin)
			ft_printf("sb\n");
	}

}

void	ft_swap_swap(t_init *ps)
{
	ft_swap_a(ps, 1);
	ft_swap_b(ps, 1);
	ft_printf("ss\n");
}