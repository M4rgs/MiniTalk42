/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:39 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/28 04:21:15 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_settozeros(char *b, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		b[i] = 0;
		i++;
	}
}

void	ft_reset(int *bit, int *c, char *z)
{
	write (2, "\n", 1);
	*bit = 0;
	*c = 0;
	ft_settozeros(z, 7000000);
}

void	ft_finish(char *z, int pid)
{
	ft_putstr(z);
	ft_settozeros(z, 7000000);
	kill(pid, SIGUSR1);
}
