/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:32 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/28 05:43:00 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	c;
	static int	bit;
	static int	pid;
	static char	z[7000000];

	(void)s;
	if (pid != info->si_pid)
	{
		ft_reset(&bit, &c, z);
		pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		c += (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_customjoinn(z, (char)c);
		if (c == '\0')
			ft_finish(z, pid);
		bit = 0;
		c = 0;
	}
	usleep(800);
	kill(pid, SIGUSR2);
}

static void	ft_pid_print(int pid)
{
	ft_putstr("\e[035;4mServer PID  ➤\e[0m\t\e[0m");
	ft_putnbr(pid);
	ft_putstr("\n\n\e[038;5;236m ✸  Waiting The Message  ✸ \e[0m\n");
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
	return (0);
}
