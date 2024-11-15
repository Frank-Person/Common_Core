/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:00:16 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:49:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*result;

	if (!string || !f)
		return (NULL);
	result = ft_calloc(ft_strlen(string) + 1, sizeof(char));
	if (!result)
		return (NULL);
	index = 0;
	while (string[index])
	{
		result[index] = (*f)(index, string[index]);
		index++;
	}
	return (result);
}
