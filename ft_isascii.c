/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:23:42 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/29 18:36:27 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (c);
	return (0);
}

int	main(void)
{
	unsigned char	c;

	c = 128;
	printf("%d\n", ft_isascii(c));
	return (0);
}
