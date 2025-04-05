/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:49:56 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/03 23:55:10 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

static volatile sig_atomic_t	g_ack = 0;

static void	check(int signal)
{
	if (signal == SIGUSR1)
		g_ack = 1;
	else
		ft_printf("Signal Received!\n");	
}

static int	ft_atoi(char *str)
{
	int		sgn;
	pid_t	num;

	num = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sgn = (*str != '-') - (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		num = (num * 10) + (*str++ - '0');
	return (num * sgn);
}

static void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		signal(SIGUSR2, check);
		signal(SIGUSR1, check);
		while (*av[2])
			ft_atob(pid, *av[2]++);
		ft_atob(pid, '\0');
	}
	else
		exit(ft_printf("Error\n"));
	return (0);
}
