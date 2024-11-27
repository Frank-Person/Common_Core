/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:41:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/27 19:10:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	nothing(va_list args)
{
	return ;
}

static void	init_arr(t_ftp *funcs)
{
	int	i;

	i = 0;
	while (i < 127)
		funcs[i++] = nothing;
	funcs['c'] = flag_c;
	funcs['s'] = flag_s;
	funcs['p'] = flag_p;
	funcs['d'] = flag_diu;
	funcs['i'] = flag_diu;
	funcs['u'] = flag_diu;
	funcs['x'] = flag_xl;
	funcs['X'] = flag_xu;
	funcs['%'] = flag_pc;
}

int	ft_printf(const char *str, ...)
{
	t_ftp	funcs[127];
	va_list	args;
	int		cnt;

	init_arr(funcs);
	cnt = 0;
	va_start(args, str);
	while (str)
	{
	}
	va_end(args);
	return (cnt);
}
