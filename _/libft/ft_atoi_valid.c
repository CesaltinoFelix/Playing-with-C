/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:41:09 by cefelix           #+#    #+#             */
/*   Updated: 2024/05/14 12:41:12 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi_valid(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	if (str[i] != '\0')
	{
		return (-1);
	}
	return (res);
}
