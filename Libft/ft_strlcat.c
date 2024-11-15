/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:28:14 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:23:26 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	dest_length;
	size_t	source_length;

	dest_length = ft_strlen(dest);
	source_length = ft_strlen(src);
	if (dest_length >= dest_size)
		return (dest_size + source_length);
	if (source_length < dest_size - dest_length)
		ft_memcpy(dest + dest_length, src, source_length + 1);
	else
	{
		ft_memcpy(dest + dest_length, src, dest_size - dest_length - 1);
		dest[dest_size - 1] = 0;
	}
	return (dest_length + source_length);
}
