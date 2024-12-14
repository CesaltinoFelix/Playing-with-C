/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:12:34 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/02 14:17:48 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithms(t_init *ps)
{
	//ft_printf("Pilha A no principio:\n");
	//ft_print_stack(ps->stack_a);

	if (ps->num_args == 2)
		two_args_alg(ps);
	else if (ps->num_args == 3)
		three_args_alg(ps);
	else  
		big_algorithm(ps);
	// ft_printf("\n\n\nPilha A no fim:\n");
	// ft_print_stack(ps->stack_a);
	// ft_printf("\n\n\nPilha B no fim:\n");
	// ft_print_stack(ps->stack_b);


}

void	two_args_alg(t_init *ps)
{
	if(!check_order(ps->stack_a))
		ft_swap_a(ps, 0);
}

void	three_args_alg(t_init *ps)
{
	if (ft_get_min_value(ps->stack_a) == ps->stack_a->value)
	{
		ft_reverse_rotate_a(ps, 0);
		ft_swap_a(ps, 0);
	}
	else if(ft_get_max_value(ps->stack_a) == ps->stack_a->value)
	{
		ft_rotate_a(ps, 0);
		if(!check_order(ps->stack_a))
			ft_swap_a(ps, 0);

	}
	else
	{
		if (ft_get_min_value(ps->stack_a) == ps->stack_a->next->value)
			ft_swap_a(ps, 0);
		else
			ft_reverse_rotate_a(ps, 0);
	}
}