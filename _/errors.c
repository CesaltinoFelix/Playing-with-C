/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:52:27 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/27 11:42:05 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}
void cleanup_and_error(t_init *ps)
{
	ft_free_matrix(ps->arguments);
	free_stacks(ps);
	error();
}