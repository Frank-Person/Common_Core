/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:27:58 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:49:42 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t n)
{
	while (*string1 && *string2 && *string1 == *string2 && n--)
	{
		string1++;
		string2++;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)string1 - *(unsigned char *)string2);
}
