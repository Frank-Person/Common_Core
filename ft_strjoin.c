/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:12 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/01 21:31:57 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tl;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	tl = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = ft_calloc(tl, sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1));
	ft_memcpy((s + ft_strlen(s1)), s2, ft_strlen(s2));
	return (s);
}
