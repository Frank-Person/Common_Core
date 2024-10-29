/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:45:45 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/29 18:37:38 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalpha(int c)
{
    if ((c > 64 && c < 91)
	|| (c > 96 && c < 123))
	return (c);
    return (0);
}

int	main(void)
{
	unsigned char   c;

	c = 'A';
	printf("%d\n%c\n", ft_isalpha(c), ft_isalpha(c));
	return (0);
}
