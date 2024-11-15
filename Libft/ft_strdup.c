/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:43:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:37:53 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	int		index;
	char	*duplicate;

	index = -1;
	duplicate = malloc((ft_strlen(string) + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (string[++index])
		duplicate[index] = string[index];
	duplicate[index] = '\0';
	return (duplicate);
}
