/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:46:46 by cefelix           #+#    #+#             */
/*   Updated: 2024/08/16 15:36:51 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal_back(int signum, int client_pid)
{
	if (signum == SIGUSR1)
	{
		if (kill(client_pid, SIGUSR1) == -1)
			write(STDERR_FILENO, "ERROR\n", 6);
	}
	else
	{
		if (kill(client_pid, SIGUSR2) == -1)
			write(STDERR_FILENO, "ERROR\n", 6);
	}
}

void	handler_bit_received(int signum, siginfo_t *info, void *ucontext)
{
	static int	client_pid;
	static int	counter;
	static int	n;

	(void)ucontext;
	if (client_pid != info->si_pid)
	{
		counter = 0;
		n = 0;
		client_pid = info->si_pid;
	}
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
	send_signal_back(signum, client_pid);
}

void	show_preloader(void)
{
	const char	*message = "STARTING SERVER";
	const char	*done_message = "\rDone!\n";

	while (1)
	{
		write(STDOUT_FILENO, message, 15);
		usleep(500000);
		write(STDOUT_FILENO, "\rSTARTING SERVER.", 17);
		usleep(500000);
		write(STDOUT_FILENO, "\rSTARTING SERVER..", 18);
		usleep(500000);
		write(STDOUT_FILENO, "\rSTARTING SERVER...", 19);
		usleep(500000);
		break ;
	}
	write(STDOUT_FILENO, "\r                  ", 19);
	write(STDOUT_FILENO, done_message, 7);
}

int	main(void)
{
	struct sigaction	action;	
	const char			*welcome_message;

	show_preloader();
	welcome_message = "Ola eu sou o Cesaltino Felix 😀\
, seja bem-vindo ao meu servidor!\n";
	write(STDOUT_FILENO, welcome_message, ft_strlen(welcome_message));
	write(STDOUT_FILENO, "Server PID: ", 12);
	ft_putnbr(getpid());
	write(STDOUT_FILENO, "\n", 1);
	action.sa_sigaction = handler_bit_received;
	action.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
