/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:02:41 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/10/29 18:36:14 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (c);
	return (0);
}

int	main(void)
{
	unsigned char	c;

	c = '9';
	printf("%d\n%c\n", ft_isdigit(c), ft_isdigit(c));
	return (0);
}
