/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:21:01 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/27 11:40:42 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stacks(t_init *ps)
{
    t_list *temp;

    while (ps->stack_a)
    {
        temp = ps->stack_a;
        ps->stack_a = ps->stack_a->next;
        free(temp);
    }

    while (ps->stack_b)
    {
        temp = ps->stack_b;
        ps->stack_b = ps->stack_b->next;
        free(temp);
    }
}

void	ft_free_matrix(char **matrix)
{
	if (matrix)
	{
		int	i;

		i = -1;
		while (matrix[++i])
			free(matrix[i]);
		free(matrix);
	}
}
