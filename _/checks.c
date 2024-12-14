/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:33:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/30 13:06:25 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_is_num(t_init *ps, char *str)
{
	int	i;

	i = 0;
	if((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
		{
			cleanup_and_error(ps);
		}
		i++;
	}
}


void ft_check_max_min(t_init *ps, char *str)
{
    int len = ft_strlen(str);

    if ((len > 11) || 
        (len == 11 && str[0] == '-' && ft_strncmp("-2147483648", str, 11) < 0) ||
        (len > 10) || 
        (len == 10 && str[0] != '-' && ft_strncmp("2147483647", str, 10) < 0))
    {
        cleanup_and_error(ps);
    }
}

void	check_doubles(t_init *ps)
{
	t_list *stack_a_i;
	t_list *stack_a_j;

	stack_a_i = ps->stack_a;
	while (stack_a_i)
	{
		stack_a_j = stack_a_i->next;
		while (stack_a_j)
		{
			if (stack_a_i->value == stack_a_j->value)
				cleanup_and_error(ps);
			stack_a_j = stack_a_j->next;
		}
		stack_a_i = stack_a_i->next;
	}
}
int	check_order(t_list *stack)
{
	t_list	*tem_stack;
	tem_stack = stack;
	while (tem_stack->next)
	{
		if (tem_stack->value > tem_stack->next->value)
			return (0);
		tem_stack = tem_stack->next;
	}
	return (1);
}