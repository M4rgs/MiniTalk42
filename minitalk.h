/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:23:34 by tamounir          #+#    #+#             */
/*   Updated: 2025/01/28 04:08:51 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_customjoinn(char *str, char c);
void	ft_putnbr(int n);

#endif