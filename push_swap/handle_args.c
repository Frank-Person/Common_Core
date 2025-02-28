/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:50:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/02/28 18:21:50 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *alpha)
{
	long	num;
	int		sgn;

	if (!alpha)
		return (0);
	num = 0;
	sgn = 1;
	while (*alpha == ' ' || (*alpha > 8 && *alpha < 14))
		alpha++;
	if (*alpha++ == '-')
		sgn *= -1;
	while (*alpha >= '0' && *alpha <= '9')
		num = (num * 10) + (*alpha++ - '0');
	return (num * sgn);
}

static size_t	ft_hmw(char const *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
	}
	return (cnt);
}

static char	**r_split(char **strs, char const *str, char c)
{
	char	*s_str;

	while (*str && *str == c)
		str++;
	if (!*str)
		return (strs);
	s_str = (char *)str;
	while (*str && *str != c)
		str++;
	*strs = ft_substr(s_str, 0, str - s_str);
	if (!*strs)
		return (NULL);
	return (r_split(strs + 1, str, c));
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	char	**stpt;

	if (!str)
		return (NULL);
	strs = ft_calloc(ft_hmw(str, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	stpt = strs;
	if (!r_split(strs, str, c))
	{
		while (*stpt)
			free(*stpt++);
		free(strs);
		return (NULL);
	}
	return (strs);
}
