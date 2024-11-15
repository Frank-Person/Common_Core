/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:16:02 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:08:49 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*content;

	if (!list || !f || !del)
		return (NULL);
	new_list = NULL;
	while (list)
	{
		content = f(list->content);
		node = ft_lstnew(content);
		if (!node)
		{
			if (content)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		list = list->next;
	}
	return (new_list);
}

// int	main()
// {
// 	t_list	*lst;
// 	t_list	*nw_lst;

// 	lst = ft_lstnew("1");
// 	ft_lstadd_back(&lst, ft_lstnew("2"));
// 	ft_lstadd_back(&lst, ft_lstnew("3"));
// 	ft_lstadd_back(&lst, ft_lstnew("4"));
// 	nw_lst = ft_lstmap(lst, )
// 	printf("%s\n", );
// 	return (0);
// }
