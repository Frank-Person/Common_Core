/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:53:31 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:14:23 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_sorted(t_lst *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_lstclear(t_lst **list)
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

int	check_doubles(t_lst *stack)
{
	t_lst	*current;
	t_lst	*next;

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

void	liberate(t_lst *stack)
{
	ft_lstclear(&stack);
	exit(write(2, "Error\n", 6));
}
