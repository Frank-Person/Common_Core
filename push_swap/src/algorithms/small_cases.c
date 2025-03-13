/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:59:00 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/10 18:43:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

 static t_list	*lowest_value(t_list *stack_a)
{
	t_list *current;
	t_list *lowest;

	current = stack_a;
	lowest = stack_a;
	while (current)
	{
		if (lowest->content > current->content)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

void	sort_to_3(t_list **stack_a)
{
	if (stack_sorted(*stack_a))
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content
	&& (*stack_a)->content > (*stack_a)->next->next->content)
		op_rotate(stack_a, 'a', 1);
	else if ((*stack_a)->next->content > (*stack_a)->content
	&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		op_rev_rotate(stack_a, 'a', 1);
	if ((*stack_a)->content > (*stack_a)->next->content)
		op_swap(stack_a, 'a', 1);
}

void	sort_to_4(t_list **stack_a, t_list *stack_b)
{
  t_list  *lowest;

  lowest = lowest_value(*stack_a);
	if (stack_sorted(*stack_a))
		return ;
	while (*stack_a != lowest)
    op_rotate(stack_a, 'a', 1);
  op_push(stack_a, &stack_b, 'b');
  sort_to_3(stack_a);
  op_push(&stack_b, stack_a, 'a');
}

void	sort_to_5(t_list **stack_a, t_list *stack_b)
{
  t_list  *lowest;

  lowest = lowest_value(*stack_a);
  if (stack_sorted(*stack_a))
		return ;
  while (*stack_a != lowest)
    op_rotate(stack_a, 'a', 1);
  op_push(stack_a, &stack_b, 'b');
  sort_to_4(stack_a, stack_b);
  op_push(&stack_b, stack_a, 'a');
}
