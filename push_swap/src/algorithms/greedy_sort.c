/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_chunk_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:37:21 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/20 18:19:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	rotation(t_lst *stack, int min, int max, int size)
{
	t_lst	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		if (current->index >= min && current->index <= max)
			break ;
		current = current->next;
		i++;
	}
	if (i > (size / 2))
		return (-1);
	return (1);
}

static int	check_chunk(t_lst *stack_a, int min, int max)
{
	t_lst	*current;

	current = stack_a;
	while (current)
	{
		if (current->index >= min && current->index <= max)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	push_back(t_lst **stack_a, t_lst **stack_b, int size)
{
	int	max;

	max = size - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == max)
		{
			op_push(stack_b, stack_a, 'a');
			max--;
		}
		else if (rotation(*stack_b, max, max, ft_lstsize(*stack_b)) > 0)
			op_rotate(stack_b, 'b', 1);
		else
			op_rev_rotate(stack_b, 'b', 1);
	}
}

void	greedy_sort(t_lst **stack_a, t_lst **stack_b, int size, int num_chunks)
{
	static int	min;
	static int	max;

	max = size / num_chunks;
	while (*stack_a && min < size)
	{
		if (max > size)
			max = size;
		while (check_chunk(*stack_a, min, max))
		{
			if ((*stack_a)->index >= min && (*stack_a)->index <= max)
			{
				op_push(stack_a, stack_b, 'b');
				if ((*stack_b)->index < (min + max) / 2)
					op_rotate(stack_b, 'b', 1);
			}
			else if (rotation(*stack_a, min, max, ft_lstsize(*stack_a)) > 0)
				op_rotate(stack_a, 'a', 1);
			else
				op_rev_rotate(stack_a, 'a', 1);
		}
		min = max;
		max += size / num_chunks;
	}
	push_back(stack_a, stack_b, size);
}
