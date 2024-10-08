/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:50:04 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 13:04:38 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_is_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_max_min(char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((len > 11) || \
	(len == 11 && str[0] == '-' && \
	ft_strncmp("-2147483648", str, 11) < 0) || \
	(len == 10 && str[0] != '-' && ft_strncmp("2147483647", str, 10) < 0))
	{
		return (0);
	}
	return (1);
}
