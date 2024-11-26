/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:41:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/26 22:16:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	case_c(va_list args)
{
	char	c;

	c = va_arg(args, char);
	return (write(1, &c, 1));
}

static int	case_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		return (write(1, "(null)"), 6);
	return (write(1, &s, ft_strlen(s)));
}

int	ft_printf(const char *str, ...)
{
	
}
