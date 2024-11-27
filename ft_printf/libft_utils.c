/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:35:55 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/27 13:03:30 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_calloc(size_t nmb, size_t sz)
{
	void	*res;

	res = malloc(nmb * sz);
	if (!res)
		return (NULL);
	while (nmb--)
		*res++ = '\0';
	return (res);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*start;

	start = dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (start);
}

static char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = -1;
	dup = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (str[++i])
		dup[i] = str[i];
	return (dup);
}

static char	*ft_itoa_base(int nbr, int bsize, char *base)
{
	char	*str;
	char	arr[20];
	int		i;
	int		sgn;

	i = 20;
	sgn = (nbr > 0) - (nbr < 0);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		arr[--i] = &base[(nbr % bsize) * sgn];
		nbr /= bsize;
	}
	if (sgn < 0)
		arr[--i] = '-';
	str = ft_calloc((20 - i) + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_memcpy(str, arr + i, (20 - i)));
}
