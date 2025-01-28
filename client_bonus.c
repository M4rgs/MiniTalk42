/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:29 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/28 05:48:35 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_reciever(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr("\e[35m⚡︎\e[0m\e[1;34m    Server received message ✅\e[0m\
      \e[35m⚡︎\e[0m\n");
	}
	else if (signal == SIGUSR2)
		return ;
	exit (0);
}

static void	ft_bit_sender(int pid, char chara)
{
	int	bit;

	bit = 0;
	signal(SIGUSR2, ft_reciever);
	while (bit < 8)
	{
		if ((chara & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write (2, "\e[033;0;31m→  PID not correct. ❌\e[0m\n", 42);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write (2, "\e[033;0;31m→  PID not correct. ❌\e[0m\n", 42);
				exit(1);
			}
		}
		pause();
		bit++;
	}
}

static void	ft_send_str(int pid, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_bit_sender(pid, s[i]);
		i++;
	}
	ft_bit_sender(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_putstr("\e[033;0;31m→  PID not correct. ❌\e[0m\n");
			return (1);
		}
		signal(SIGUSR1, ft_reciever);
		ft_send_str(pid, argv[2]);
		while (1)
			pause();
	}
	else
	{
		ft_putstr("\e[033;0;31m→  Error: Wrong Format\e[0m\n");
		ft_putstr("\e[033;0;35m→  Try: ./client [PID] [MESSAGE]\e[0m\n");
	}
	return (0);
}
