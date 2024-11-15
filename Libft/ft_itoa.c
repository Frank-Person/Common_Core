/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:45 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:02:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int number)
{
	char	*string;
	char	array[11];
	int		index;
	int		sign;

	index = 11;
	sign = (number > 0) - (number < 0);
	if (number == 0)
		return (ft_strdup("0"));
	while (number)
	{
		array[--index] = (number % 10) * sign + '0';
		number /= 10;
	}
	if (sign < 0)
		array[--index] = '-';
	string = ft_calloc((11 - index) + 1, sizeof(char));
	if (!string)
		return (NULL);
	return (ft_memcpy(string, array + index, (11 - index)));
}
