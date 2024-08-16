/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:46:14 by cefelix           #+#    #+#             */
/*   Updated: 2024/08/16 15:11:28 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	null_signal(int pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(500);
	}
}

void	error_sending_signal(void)
{
	write(2, "Error sending SIGUSR\n", 22);
	server_error();
	exit(EXIT_FAILURE);
}

void	handler_bit_received(int signum)
{
	static int	counter;
	static int	n;

	if (signum == SIGUSR1)
		n = n * 2 + 1;
	else
		n = n * 2 + 0;
	counter++;
	if (counter == 8)
	{
		write(1, &n, 1);
		if (n == '\0')
			write(1, "\n", 1);
		counter = 0;
		n = 0;
	}
}

void	convert_to_bits(char c, int pid)
{
	char	bit;
	int		i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_sending_signal();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_sending_signal();
		}
		i--;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	signal(SIGUSR1, handler_bit_received);
	signal(SIGUSR2, handler_bit_received);
	if (argc != 3)
	{
		eg_usage();
		return (EXIT_FAILURE);
	}
	pid = ft_atoi_valid(argv[1]);
	i = 0;
	if (pid <= 0)
	{
		invalid_pid();
		return (EXIT_FAILURE);
	}
	while (argv[2][i])
	{
		convert_to_bits(argv[2][i], pid);
		i++;
	}
	null_signal(pid);
	return (EXIT_SUCCESS);
}
