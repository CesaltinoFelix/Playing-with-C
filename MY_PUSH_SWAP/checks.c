/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:33:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/26 14:12:45 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_is_num(char **arguments, char *str)
{
	int	i;

	i = 0;
	if((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
		{
			ft_free_matrix(arguments);
			error();	
		}
		i++;
	}
}

void	ft_check_max_min(t_init *ps, char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[0] == '-')
		{
			if (len > 11)
			{
				if(ps->has_matrix_arguments)
				ft_free_matrix(ps);
				free_stacks(ps);
				error();
			}
			if (len == 11 && ft_strncmp("-2147483648", str, 11) < 0)
			{	
				if(ps->has_matrix_arguments)
				ft_free_matrix(ps->arguments);
				free_stacks(ps);
				error();
			}
		}
		else
		{
			if (len > 10)
			{
				if(ps->has_matrix_arguments)
				ft_free_matrix(ps);
				free_stacks(ps);
				error();
			}
			if (len == 10 && ft_strncmp("2147483647", str, 10) < 0)
			{	
				if(ps->has_matrix_arguments)
				ft_free_matrix(ps);
				free_stacks(ps);
				error();
			}
		}
		i++;
	}
}