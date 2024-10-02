/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:53:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/02 14:15:54 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index(t_list *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

int	ft_get_best_option(t_list *a, int b)
{
	long int	value;
	t_list		*tmp;
	
	value = INT_MAX;
	if (b > ft_get_max_value(a) || b < ft_get_min_value(a))
		return (ft_get_min_value(a));
	else
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->value > b)
			{
				if (tmp->value < value)
					value = tmp->value;
			}
			tmp = tmp->next;
		}
	}
	return (value);
}

void	ft_set_direction(t_init *ps, t_helper *vars)
{
	if (vars->index <= ps->num_values_a / 2)
	{
		vars->stack_a = vars->index;
		vars->a_direction = -1;
	}
	else if (vars->index > ps->num_values_a / 2)
	{
		vars->stack_a = ps->num_values_a - vars->index;
		vars->a_direction = 1;
	}
	if (vars->i <= ps->num_values_b / 2)
	{
		vars->stack_b = vars->i + 1;
		vars->b_direction = -1;
	}
	else if (vars->i > ps->num_values_b / 2)
	{
		vars->stack_b = ps->num_values_b - vars->i + 1;
		vars->b_direction = 1;
	}
}

void	ft_put_min_top(t_init *ps, t_list *stack, int num_elements)
{
	int	min;
	int	direction;
	int	index;

	min = ft_get_min_value(stack);
	index = ft_get_index(stack, min);

	// Determinar a direção da rotação
	if (index <= num_elements / 2)
		direction = -1;
	else
		direction = 1;

	// Executar a rotação até que o valor mínimo esteja no topo
	while (ps->stack_a->value != min)
	{
		if (direction == -1)
			ft_rotate_a(ps, 0);  // Rotaciona para cima
		else
			ft_reverse_rotate_a(ps, 0);  // Rotaciona para baixo
	}

	// O valor mínimo deve estar agora no topo da pilha A
}


