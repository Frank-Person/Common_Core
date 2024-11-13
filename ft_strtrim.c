/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:58:11 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/08 14:33:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *st)
{
	char	*r;
	size_t	s;
	size_t	e;

	if (!s1 || !st)
		return (NULL);
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_strchr(st, s1[s]))
		s++;
	while (e > s && ft_strchr(st, s1[e - 1]))
		e--;
	r = ft_calloc((e - s) + 1, sizeof(char));
	if (!r)
		return (NULL);
	ft_memcpy(r, s1 + s, (e - s));
	return (r);
}
