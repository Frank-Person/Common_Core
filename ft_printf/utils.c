/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:35:55 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/27 18:13:24 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_itoa_base(long long nbr, int bsize, char *base)
{
	static char	arr[20];
	int			i;
	int			sgn;

	i = 20;
	sgn = (nbr > 0) - (nbr < 0);
	while (nbr > -1)
	{
		arr[--i] = base[(nbr % bsize)];
		nbr /= bsize;
	}
	if (sgn < 0)
		arr[--i] = '-';
	return (&arr[i]);
}
