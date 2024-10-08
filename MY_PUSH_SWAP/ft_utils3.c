/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:49 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/08 16:45:52 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stack_get_top(t_node *list)
{
	return (list);
}

t_node	*ft_stack_get_last(t_node *list)
{
	t_node	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list;
		list = list->next;
	}
	return (tmp);
}

void	ft_reverse_rotate_rotate(t_node **a, t_node **b)
{
	ft_reverse_rotate_a(a, 0);
	ft_reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}

void	ft_rotate_rotate(t_node **a, t_node **b)
{
	ft_rotate_a(a, 0);
	ft_rotate_b(b, 0);
	ft_printf("rr\n");
}

char	*join_args(int ac, char **av)
{
	int		total_length;
	int		i;
	int		index;
	int		arg_length;
	char	*joined_string;

	total_length = 0;
	i = 1;
	index = 0;
	while (i < ac)
		total_length += ft_strlen(av[i++]) + 1;
	joined_string = malloc(total_length);
	if (!joined_string)
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		arg_length = ft_strlen(av[i]);
		ft_memcpy(joined_string + index, av[i], arg_length);
		index += arg_length;
		joined_string[index++] = ' ';
	}
	if (index > 0)
		joined_string[index - 1] = '\0';
	return (joined_string);
}
