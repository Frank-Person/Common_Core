/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:53:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/08 21:53:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

static t_data	*db(void)
{
	static t_data	db;

	return (&db);
}

static void	msg_received(int pid, int size_check, char *str)
{
	kill(pid, SIGUSR2);
	if (size_check)
	{
		ft_printf("%s\n", str);
		free(db()->tmp);
	}
	db()->size = 0;
	db()->index = 0;
}

static void	set_size(int pid)
{
	db()->size = db()->bin;
	if (db()->size == 0)
		msg_received(pid, 0, NULL);
	db()->bin = 0;
	db()->bit = 0;
}

static void	sig_handler(int sig, siginfo_t *to_handle, void *trash)
{
	(void)trash;
	if (sig == SIGUSR1)
		db()->bin |= (1 << db()->bit);
	db()->bit++;
	if (db()->bit == 32 && db()->size == 0)
	{
		set_size(to_handle->si_pid);
		if (db()->size != 0)
		{
			db()->str = malloc((db()->size + 1) * sizeof(char));
			if (!db()->str)
				return ;
			db()->tmp = db()->str;
		}
	}
	if (db()->bit == 8 && db()->size != 0)
	{
		db()->str[db()->index++] = db()->bin;
		if (db()->bin == 0 && db()->size != 0)
			msg_received(to_handle->si_pid, 1, db()->tmp);
		db()->bin = 0;
		db()->bit = 0;
	}
	kill(to_handle->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		exit(ft_printf("Error\n"));
	db()->pid = getpid();
	ft_printf("Server PID: %d\n", db()->pid);
	db()->act.sa_sigaction = sig_handler;
	sigemptyset(&db()->act.sa_mask);
	db()->act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &db()->act, NULL);
	sigaction(SIGUSR2, &db()->act, NULL);
	while (1)
		pause();
	return (0);
}
