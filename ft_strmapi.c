/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:00:16 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 16:49:45 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	if (!s || !f)
		return (NULL);
	r = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = (*f)(i, s[i]);
		i++;
	}
	return (r);
}
