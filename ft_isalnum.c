/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:16:18 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/29 18:38:12 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91)
        	|| (c > 96 && c < 123)
		|| (c > 47 && c < 58))
        	return (c);
	return (0);
}

int	main(void)
{
	unsigned char	c;

	c = 'A';
	printf("%d\n%c\n", ft_isalnum(c), ft_isalnum(c));
	c = 'a';
	printf("%d\n%c\n", ft_isalnum(c), ft_isalnum(c));
	c = '9';
	printf("%d\n%c\n", ft_isalnum(c), ft_isalnum(c));
	c = '*';
	printf("%d\n%c\n", ft_isalnum(c), ft_isalnum(c));
	return (0);
}
