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

static int	rotation_cost(t_lst *stack, int chunk_min, int chunk_max, int size)
{
	t_lst *current;
	int	  i;

	current = stack;
	i = 0;
	while (current)
	{
		if (current->index >= chunk_min && current->index <= chunk_max)
			break ;
		current = current->next;
		i++;
	}
	if (i > (size / 2))
		return (-1);
	return (1);
}

static int	check_chunk(t_lst *stack_a, int chunk_min, int chunk_max)
{
	t_lst *current;

	current = stack_a;
	while (current)
	{
		if (current->index >= chunk_min && current->index <= chunk_max)
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
		else if (rotation_cost(*stack_b, max, max, ft_lstsize(*stack_b)) > 0)
			op_rotate(stack_b, 'b', 1);
		else
			op_rev_rotate(stack_b, 'b', 1);
	}
}

void  greedy_sort(t_lst **stack_a, t_lst **stack_b, int size, int num_chunks)
{
	static int	chunk_min;
	static int	chunk_max;

	chunk_max = size / num_chunks;
	while (*stack_a && chunk_min < size)
	{
		if (chunk_max > size)
			chunk_max = size;
		while (check_chunk(*stack_a, chunk_min, chunk_max))
		{
			if ((*stack_a)->index >= chunk_min && (*stack_a)->index <= chunk_max)
			{
				op_push(stack_a, stack_b, 'b');
				if ((*stack_b)->index < (chunk_min + chunk_max) / 2)
					op_rotate(stack_b, 'b', 1);
			}
			else if (rotation_cost(*stack_a, chunk_min, chunk_max, ft_lstsize(*stack_a)) > 0)
				op_rotate(stack_a, 'a', 1);
			else
				op_rev_rotate(stack_a, 'a', 1);
		}
		chunk_min = chunk_max;
		chunk_max += size / num_chunks;
	}
	push_back(stack_a, stack_b, size);
}

