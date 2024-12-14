/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:56:29 by cefelix           #+#    #+#             */
/*   Updated: 2024/08/16 14:57:07 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	eg_usage(void)
{
	const char	*msg;

	msg = "Usage: ./client <PID> <message>\n";
	write(2, msg, ft_strlen(msg));
}

void	invalid_pid(void)
{
	const char	*error_msg;

	error_msg = "Easy boy 😀... Your PID must be a (INTEGER) positive value.\n";
	write(2, error_msg, ft_strlen(error_msg));
	eg_usage();
}

void	server_error(void)
{
	write(2, "Check if the server is still running\n", 37);
}
