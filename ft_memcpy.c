/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:08:01 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 19:39:51 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*b;

	b = dst;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (b);
}
