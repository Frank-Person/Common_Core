/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:39:46 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/19 13:25:20 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t legnth)
{
	size_t	little_length;

	little_length = ft_strlen(little);
	if (!little_length)
		return ((char *)big);
	if (!legnth)
		return (NULL);
	while (*big && little_length <= legnth--)
	{
		if (ft_strncmp(big, little, little_length) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
