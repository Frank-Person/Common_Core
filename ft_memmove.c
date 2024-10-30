/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:38:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/30 01:36:53 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;
	size_t			i;

	td = (unsigned char *) dst;
	ts = (unsigned char *) src;
	i = -1;
	if (td > ts)
	{
		while (n--)
			td[n] = ts[n];
	}
	else
	{
		while (++i < n)
			td[i] = ts[i];
	}
	return (dst);
}
