/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:57:02 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:14:49 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lstsize(t_lst *list)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

t_lst	*ft_lstnew(int content)
{
	struct s_list	*node;

	node = malloc(sizeof(struct s_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_lst	*ft_lstlast(t_lst *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_lst	*ft_lst_bflast(t_lst *list)
{
	t_lst	*current;

	if (!list)
		return (NULL);
	current = list;
	while (current->next && current->next->next)
		current = current->next;
	return (current);
}
