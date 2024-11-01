/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:28:14 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/01 18:24:18 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t ds)
{
	size_t	dl;
	size_t	sl;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dl >= ds)
		return (ds + sl);
	if (sl < ds - dl)
		ft_memcpy(dst + dl, src, sl + 1);
	else
	{
		ft_memcpy(dst + dl, src, ds - dl - 1);
		dst[ds - 1] = 0;
	}
	return (dl + sl);
}
