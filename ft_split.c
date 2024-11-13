/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:30:15 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/12 15:51:41 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wrd_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

static char	**r_split(char **str, char const *s, char c)
{
	char	*ss;

	while (*s && *s == c)
		s++;
	if (!*s)
		return (str);
	ss = (char *)s;
	while (*s && *s != c)
		s++;
	*str = ft_substr(ss, 0, s - ss);
	if (!*str)
		return (NULL);
	return (r_split(str + 1, s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**err;

	if (!s)
		return (NULL);
	str = ft_calloc(wrd_cnt(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	err = str;
	if (!r_split(str, s, c))
	{
		while (*err)
			free(*err++);
		free(str);
		return (NULL);
	}
	return (str);
}
