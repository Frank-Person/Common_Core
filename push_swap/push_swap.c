/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:47:08 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:17:13 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves = 0;

static void	print_stack(t_lst *stack)
{
	if (stack)
	{
		printf("node: %d, index: %d\n", stack->content, stack->index);
		print_stack(stack->next);
	}
}

static void	check_algorithm(t_lst **stack_a, t_lst **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (!stack_sorted(*stack_a) && size == 2)
		op_swap(stack_a, 'a', 1);
	else if (size == 3)
		sort_to_3(stack_a);
	else if (size == 4)
		sort_to_4(stack_a, *stack_b);
	else if (size == 5)
		sort_to_5(stack_a, *stack_b);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = build_stack(++argv);
		if (check_doubles(stack_a))
			exit(write(2, "Error\n", 6));
		assign_indexes(stack_a);
		printf("OG Stack:\n");
		print_stack(stack_a);
		printf("\n");
		check_algorithm(&stack_a, &stack_b);
		printf("\nSorted Stack:\n");
		print_stack(stack_a);
		printf("\nMoves: %d\n", moves);
		ft_lstclear(&stack_a);
		free(stack_b);
	}
	return (0);
}
