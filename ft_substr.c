/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 20:57:29 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int strt, size_t ln)
{
	char	*ss;
	size_t	sz;

	if (!s)
		return (NULL);
	sz = ft_strlen(s);
	if (strt >= sz)
		return (ft_calloc(1, sizeof(char)));
	if (ln > sz - strt)
		ln = sz - strt;
	ss = ft_calloc(ln + 1, sizeof(char));
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s + strt, ln);
	return (ss);
}
