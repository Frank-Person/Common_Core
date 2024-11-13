/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:38:15 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/13 02:22:42 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	c;

	c = ft_lstsize(lst) - 1;
	if (!lst)
		return (NULL);
	while (c)
	{
		lst = lst->next;
		c--;
	}
	return (lst);
}
