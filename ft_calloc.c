/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:35:53 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/01 02:15:09 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nm, size_t s)
{
	void	*ar;

	ar = malloc((nm + 1) * sizeof(s));
	if (!ar)
		return (NULL);
	if (nm == 0 || s == 0)
	{
		ar = NULL;
		return (ar);
	}
	ft_bzero(ar, nm);
	return (ar);
}
