/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:45 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 18:56:26 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*r;
	int		c;
	int		m;
	long	nb;

	c = 0;
	m = 10;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		c++;
	}
	while (nb % m < nb)
	{
		c++;
		m *= 10;
	}
	r = ft_calloc(c + 1, sizeof(char));
	if (!r)
		return (NULL);
	return (r);
}
