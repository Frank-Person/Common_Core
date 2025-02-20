/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:45:04 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/02/20 21:15:35 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *stack)
{
	write(1, "s", 2);
	(write(1, &(stack->name), 2)) && (write(1, "\n", 2));
}

void	op_push(t_stack *stack)
{

}

void	op_rotate(t_stack *stack)
{

}

void	op_rev_rotate(t_stack *stack)
{
	
}
t_stack	*new_stack(char name)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	new->name = name;
	new->swap = op_swap;
}

int main()
{
	t_stack *a;
	t_stack *b;

	a = new_stack("a");
	b = new_stack("b");
	a->swap(&a);
}
