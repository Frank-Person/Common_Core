/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:43:07 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/13 19:27:00 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*nxt;

	if (!lst || !del)
		return (NULL);
	while (*lst)
	{
		nxt = *lst->next;
		ft_lstdelone(*lst, del);
		*lst = nxt;
	}
}
