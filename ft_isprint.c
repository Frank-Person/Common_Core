/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:57:29 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/29 18:35:06 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (c);
	return (0);
}

int	main(void)
{
	unsigned char	c;

	c = '~';
	printf("%d\n%c\n", ft_isprint(c), ft_isprint(c));
	return (0);
}
