/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:59:00 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:13:48 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_lst	*lowest_index(t_lst *stack_a)
{
	t_lst	*current;
	t_lst	*lowest;

	current = stack_a;
	lowest = stack_a;
	while (current)
	{
		if (lowest->index > current->index)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	sort_to_3(t_lst **stack_a)
{
	if (stack_sorted(*stack_a))
		return ;
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		op_rotate(stack_a, 'a', 1);
	else if ((*stack_a)->next->index > (*stack_a)->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
		op_rev_rotate(stack_a, 'a', 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		op_swap(stack_a, 'a', 1);
}

void	sort_to_4(t_lst **stack_a, t_lst *stack_b)
{
	t_lst *lowest;

	lowest = lowest_index(*stack_a);
	if (stack_sorted(*stack_a))
		return ;
	while (*stack_a != lowest)
	{
		if ((*stack_a)->index <= 1)
			op_rotate(stack_a, 'a', 1);
		else
			op_rev_rotate(stack_a, 'a', 1);
	}
	op_push(stack_a, &stack_b, 'b');
	sort_to_3(stack_a);
	op_push(&stack_b, stack_a, 'a');
}

void	sort_to_5(t_lst **stack_a, t_lst *stack_b)
{
	t_lst *lowest;

	lowest = lowest_index(*stack_a);
	if (stack_sorted(*stack_a))
		return ;
	while (*stack_a != lowest)
	{
		if ((*stack_a)->index <= 2)
			op_rotate(stack_a, 'a', 1);
		else
			op_rev_rotate(stack_a, 'a', 1);
	}
	op_push(stack_a, &stack_b, 'b');
	sort_to_4(stack_a, stack_b);
	op_push(&stack_b, stack_a, 'a');
}
