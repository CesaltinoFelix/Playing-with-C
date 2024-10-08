/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:52 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 11:38:03 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_init_stack(t_node **list, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	new->value = value;
	new->next = *list;
	*list = new;
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_validate_global(ac, av, &stack_a))
		return (0);
	if (ft_count_elem(stack_a) == 2)
		two_args_alg(&stack_a);
	else if (ft_count_elem(stack_a) == 3)
		three_args_alg(&stack_a);
	else
		big_algorithm(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
