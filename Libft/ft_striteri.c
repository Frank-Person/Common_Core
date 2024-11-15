/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:03:04 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:38:49 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *string, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (!string || !f)
		return ;
	index = 0;
	while (string[index])
	{
		(*f)(index, &string[index]);
		index++;
	}
}
