/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:01:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:57:53 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *number)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*number == ' ' || (*number >= '\t' && *number <= '\r'))
		number++;
	if (*number == '+' || *number == '-')
	{
		sign = (*number == '+') - (*number == '-');
		number++;
	}
	while (ft_isdigit(*number))
	{
		result = (result * 10) + (*number - '0');
		number++;
	}
	return (result * sign);
}
