/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:41:59 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/27 18:15:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flag_c(va_list args)
{
	char	chr;

	chr = va_arg(args, char);
	return (write(1, &chr, 1));
}

int	flag_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	flag_p(va_list args)
{
	unsigned long	adrs;
	char			*str;

	adrs = va_arg(args, void *);
	str = ft_itoa_base(adrs, 16, HEX_L);
	if (!adrs)
		return (write(1, "(nil)", 5));
	return (write(1, str, ft_strlen(str)));
}

int	flag_diu(va_list args)
{
	long long	nbr;
	char		*str;

	nbr = va_arg(args, int);
	str = ft_itoa_base(nbr, 10, DEX);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
