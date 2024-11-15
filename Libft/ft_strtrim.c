/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:58:11 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:54:51 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *string, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!string || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(string);
	while (string[start] && ft_strchr(set, string[start]))
		start++;
	while (end > start && ft_strchr(set, string[end - 1]))
		end--;
	trimmed = ft_calloc((end - start) + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, string + start, (end - start));
	return (trimmed);
}
