/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:42:03 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:37:12 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int ascii)
{
	while (*string)
	{
		if (*string == (unsigned char)ascii)
			return ((char *)string);
		string++;
	}
	if ((unsigned char)ascii == '\0')
		return ((char *)string);
	return (NULL);
}
