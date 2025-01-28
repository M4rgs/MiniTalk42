/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:32 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/28 04:08:46 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_reset(int *bit, int *c, char *p)
{
	write (2, "\n", 1);
	*bit = 0;
	*c = 0;
	free(p);
	return (NULL);
}

static char	*ft_finish(char *p, int pid)
{
	ft_putstr(p);
	kill(pid, SIGUSR1);
	free(p);
	return (NULL);
}

static void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	c;
	static int	bit;
	static int	pid;
	static char	*p;

	(void)s;
	if (pid != info->si_pid)
	{
		p = ft_reset(&bit, &c, p);
		pid = info->si_pid;
	}
	if (signal == SIGUSR1)
		c += (1 << bit);
	bit++;
	if (bit == 8)
	{
		p = ft_customjoinn(p, (char)c);
		if (c == '\0')
			p = ft_finish(p, pid);
		bit = 0;
		c = 0;
	}
	usleep(800);
	kill(pid, SIGUSR2);
}

static void	ft_pid_print(int pid)
{
	ft_putstr("  \e[1;34;4m Server Bonus PID ➤ \e[0m   \e[0m");
	ft_putnbr(pid);
	ft_putstr("\n\n \e[038;5;243m  ✸  Waiting For Message... ✸\n\e[0m\n");
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
