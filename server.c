/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:37 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/13 08:23:38 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static char	c;
	static int	bit;
	static int	pid;

	(void)s;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		c += (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c != '\0')
			ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

static void	ft_pid_print(int pid)
{
	ft_putstr_fd("\e[035;4mServer PID  ➤\e[0m\t\e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\n\e[038;5;236m ✸  Waiting The Message  ✸ \e[0m\n", 1);
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_pid_print(pid);
	sig.sa_sigaction = ft_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
