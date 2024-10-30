/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:08:01 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/30 01:14:58 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;

	td = (unsigned char *) dst;
	ts = (unsigned char *) src;
	while (n--)
		*td++ = *ts++;
	return (dst);
}
