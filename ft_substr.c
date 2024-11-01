/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:22:38 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/01 21:30:57 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int strt, size_t ln)
{
	char	*ss;

	if (!s || ln == 0)
		return (NULL);
	ss = malloc((ft_strlen(s) - strt) * sizeof(char));
	if (!ss)
		return (NULL);
	while (*s && ln)
	{
		*ss = s[strt];
		ss++;
		strt++;
		ln--;
	}
	return (ss);
}
