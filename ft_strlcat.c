/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:28:14 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/30 17:59:15 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dl;
	size_t	sl;

	if (!dst || !src)
		return (0);
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dl >= dsize)
		return (dl + sl);
	if (sl < dsize - dl)
		ft_memcpy(dst + dl, src, sl + 1);
	else
	{
		ft_memcpy(dst + dl, src, dsize - dl - 1);
		dst[dsize - 1] = 0;
	}
	return (dl + sl);
}
