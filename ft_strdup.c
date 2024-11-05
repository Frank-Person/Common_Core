/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:43:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 19:11:51 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = -1;
	dup = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	while (s[++i])
		dup[i] = s[i];
	return (dup);
}
