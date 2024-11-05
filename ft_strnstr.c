/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:39:46 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/05 15:58:02 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bg, const char *lt, size_t ln)
{
	size_t	ll;

	ll = ft_strlen(lt);
	if (!ll)
		return ((char *)bg);
	while (*bg && ll <= ln--)
	{
		if (ft_strncmp(bg, lt, ll) == 0)
			return ((char *)bg);
		bg++;
	}
	return (NULL);
}
