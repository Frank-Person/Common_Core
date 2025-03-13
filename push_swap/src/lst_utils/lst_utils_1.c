/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:53:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/08 15:57:57 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	exit(printf("Stack Sorted!"));
	return (1);
}

void	ft_lstadd_back(t_list **list, t_list *new_node)
{
	t_list	*last_node;

	if (!list || !new_node)
		return ;
	last_node = ft_lstlast(*list);
	if (last_node)
		last_node->next = new_node;
	else
		*list = new_node;
}

void	ft_lstclear(t_list **list)
{
	void	*next_node;

	if (!list)
		return ;
	while (*list)
	{
		next_node = (*list)->next;
		free(*list);
		*list = next_node;
	}
}

int	check_doubles(t_list *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack;
	while (current && current->next)
	{
		next = current->next;
		while (next)
		{
			if (current->content == next->content)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}
