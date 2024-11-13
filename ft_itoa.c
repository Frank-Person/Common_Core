/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:45 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/11 15:27:35 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	char	arr[11];
	int		i;
	int		sgn;

	i = 11;
	sgn = (n > 0) - (n < 0);
	if (n == 0)
		return (ft_strdup("0"));
	while (n)
	{
		arr[--i] = (n % 10) * sgn + '0';
		n /= 10;
	}
	if (sgn < 0)
		arr[--i] = '-';
	res = ft_calloc((11 - i) + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (ft_memcpy(res, arr + i, (11 - i)));
}
