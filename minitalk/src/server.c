/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:53:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/03 23:55:39 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

static void	ft_btoa(int sig, siginfo_t *to_handle, void *trash)
{
	static int	bin;
	static int	bit;

	(void)trash;
	if (sig == SIGUSR1)
		bin |= (1 << bit);
	kill(to_handle->si_pid, SIGUSR2);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", bin);
		if (bin == 0)
			ft_printf("\n");
		bin = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
		exit(ft_printf("Error\n"));
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = ft_btoa;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
