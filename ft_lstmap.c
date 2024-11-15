/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:16:02 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/14 20:14:14 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw_lst;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nw_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			if (content)
				del(content);
			ft_lstclear(&nw_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&nw_lst, node);
		lst = lst->next;
	}
	return (nw_lst);
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
