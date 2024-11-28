/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:56 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/28 03:53:35 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flag_pc(void)
{
	return (write(1, "%", 1));
}

int	flag_xl(va_list args)
{
	long long	nbr;
	char		*str;

	nbr = va_arg(args, int);
	str = ft_itoa_base(nbr, 16, HEX_L);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	flag_xu(va_list args)
{
	long long	nbr;
	char		*str;

	nbr = va_arg(args, int);
	str = ft_itoa_base(nbr, 16, HEX_U);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
