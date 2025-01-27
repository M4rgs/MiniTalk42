/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:23 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/27 03:57:19 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_bit_sender(int pid, char chara)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((chara & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write (2, "\e[033;0;31m→  PID not correct. ❌\e[0m\n", 42);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write (2, "\e[033;0;31m→  PID not correct. ❌\e[0m\n", 42);
				exit(0);
			}
		}
		usleep(600);
		bit++;
	}
}

void	ft_send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		ft_bit_sender(pid, msg[i]);
		i++;
	}
	ft_bit_sender(pid, '\n');
	ft_bit_sender(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3 && av[2][0] != '\0')
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr("\e[033;0;31m→  PID not correct. ❌\e[0m\n");
			return (1);
		}
		ft_send_message(pid, av[2]);
	}
	else
	{
		ft_putstr("\e[033;0;31m→  Error: Wrong Format\e[0m\n");
		ft_putstr("\e[033;0;35m→  Try: ./client [PID] [MESSAGE]\e[0m\n");
	}
}
