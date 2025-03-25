/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:45:04 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:15:19 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	op_swap(t_lst **stack, char name, int check)
{
	t_lst	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	*stack = temp;
	if (check)
	{
		write(1, "s", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	op_push(t_lst **src_stack, t_lst **dst_stack, char name)
{
	t_lst	*temp;

	if (!src_stack || !dst_stack || !*src_stack)
		return ;
	temp = *src_stack;
	*src_stack = (*src_stack)->next;
	temp->next = *dst_stack;
	*dst_stack = temp;
	write(1, "p", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	op_rotate(t_lst **stack, char name, int check)
{
	t_lst	*last;
	t_lst	*new_head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_head = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = new_head;
	if (check)
	{
		write(1, "r", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	op_rev_rotate(t_lst **stack, char name, int check)
{
	t_lst	*last;
	t_lst	*bf_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	bf_last = ft_lst_bflast(*stack);
	if (!bf_last)
		return ;
	bf_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (check)
	{
		write(1, "rr", 2);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	two_op(void (*f)(t_lst **, char, int), t_lst **a, t_lst **b, char op)
{
	if (!f || !a || !b || !*a || !*b)
		return ;
	f(a, op, 0);
	f(b, op, 1);
}
