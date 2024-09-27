/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:33:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/09/27 11:43:20 by cefelix          ###   ########.fr       */
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
