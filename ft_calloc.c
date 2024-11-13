/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:35:53 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/08 00:24:58 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nm, size_t s)
{
	void	*r;

	r = malloc(nm * s);
	if (!r)
		return (NULL);
	ft_bzero(r, nm * s);
	return (r);
}
