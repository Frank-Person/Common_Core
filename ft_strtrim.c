/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:58:11 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 15:49:54 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *st)
{
	size_t	mx;
	char	*r;

	if (!s1 || !st)
		return (NULL);
	mx = ft_strlen(st);
	r = ft_calloc((ft_strlen(s1) - (mx * 2)), sizeof(char));
	if (!r)
		return (NULL);
	while (*s1)
	{
		if (ft_strncmp(s1, st, mx) == 0 && mx)
		{
			s1++;
			mx--;
		}
		else
		{
			*r = *s1;
			r++;
			s1++;
		}
	}
	return (r);
}
