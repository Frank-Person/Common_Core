/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:49:56 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/08 21:53:20 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

static t_data	*db(void)
{
	static t_data	db;

	return (&db);
}

static void	sig_receiver(int sig)
{
	if (sig == SIGUSR1)
		db()->ack = 1;
	else if (sig == SIGUSR2)
		ft_printf("Message Received!\n");
}

static void	size_handler(char *str)
{
	db()->bit = 0;
	db()->size = ft_strlen(str);
	while (db()->bit < 32)
	{
		db()->ack = 0;
		if (db()->size & (1 << db()->bit))
			kill(db()->pid, SIGUSR1);
		else
			kill(db()->pid, SIGUSR2);
		while (!db()->ack)
			usleep(100);
		db()->bit++;
	}
}

static void	sig_handler(char c)
{
	db()->bit = 0;
	while (db()->bit < 8)
	{
		db()->ack = 0;
		if (c & (1 << db()->bit))
			kill(db()->pid, SIGUSR1);
		else
			kill(db()->pid, SIGUSR2);
		while (!db()->ack)
			usleep(100);
		db()->bit++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		while (*av[1] && (*av[1] >= '0' && *av[1] <= '9'))
			db()->pid = (db()->pid * 10) + (*av[1]++ - '0');
		if (db()->pid == 0 || kill(db()->pid, 0))
			exit(ft_printf("Invalid PID\n"));
		signal(SIGUSR2, sig_receiver);
		signal(SIGUSR1, sig_receiver);
		while (*av[2])
		{
			if (db()->size == 0)
				size_handler(av[2]);
			sig_handler(*av[2]++);
		}
		if (db()->size != 0)
			sig_handler('\0');
	}
	else
		exit(ft_printf("Error\n"));
	return (0);
}
