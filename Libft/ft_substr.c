/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:55:59 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t length)
{
	char	*substring;
	size_t	size;

	if (!string)
		return (NULL);
	size = ft_strlen(string);
	if (start >= size)
		return (ft_calloc(1, sizeof(char)));
	if (length > size - start)
		length = size - start;
	substring = ft_calloc(length + 1, sizeof(char));
	if (!substring)
		return (NULL);
	ft_memcpy(substring, string + start, length);
	return (substring);
}
