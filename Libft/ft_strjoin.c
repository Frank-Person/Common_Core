/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:40:43 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *string1, char const *string2)
{
	int		total_length;
	char	*string;

	if (!string1 || !string2)
		return (NULL);
	total_length = ft_strlen(string1) + ft_strlen(string2) + 1;
	string = ft_calloc(total_length, sizeof(char));
	if (!string)
		return (NULL);
	ft_memcpy(string, string1, ft_strlen(string1));
	ft_memcpy((string + ft_strlen(string1)), string2, ft_strlen(string2));
	return (string);
}
