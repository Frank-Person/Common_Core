/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:10:54 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 19:36:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int ascii)
{
	char	*occurrence;

	occurrence = NULL;
	while (*string)
	{
		if ((unsigned char)*string == (unsigned char)ascii)
			occurrence = (char *)string;
		string++;
	}
	if ((unsigned char)ascii == '\0')
		return ((char *)string);
	return (occurrence);
}
