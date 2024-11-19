/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:35:53 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/16 21:52:06 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t slots, size_t slot_size)
{
	void	*result;

	result = malloc(slots * slot_size);
	if (!result)
		return (NULL);
	ft_memset(result, '\0', slots * slot_size);
	return (result);
}
