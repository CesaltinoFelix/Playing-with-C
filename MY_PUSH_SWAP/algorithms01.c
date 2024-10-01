/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:50:08 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/01 09:58:29 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_algorithm(t_init *ps)
{
	while (ps->num_values_a > 3)
		ft_push_b(ps);
	
	if(!check_order(ps->stack_a))
		three_args_alg(ps);
}