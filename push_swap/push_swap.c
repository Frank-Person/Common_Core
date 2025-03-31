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

static void	check_algorithm(t_lst **stack_a, t_lst **stack_b)
{
	int	size;
	int	num_chunks;

	size = ft_lstsize(*stack_a);
	num_chunks = 5;
	if (size > 100 && size <= 500)
		num_chunks += (size - 100) / 80;
	if (!stack_sorted(*stack_a) && size == 2)
		op_swap(stack_a, 'a', 1);
	else if (size == 3)
		sort_to_3(stack_a);
	else if (size == 4)
		sort_to_4(stack_a, *stack_b);
	else if (size == 5)
		sort_to_5(stack_a, *stack_b);
	else if (size > 5)
		greedy_sort(stack_a, stack_b, size, num_chunks);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = build_stack(++argv);
		if (!stack_a && **argv != ' ' && (**argv != '\0' || *(*argv - 1) != '\0'))
			exit(write(2, "Error\n", 6));
		else if (!stack_a)
			exit(1);
		else if (check_doubles(stack_a))
			liberate(stack_a);
		assign_indexes(stack_a);
		check_algorithm(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
		free(stack_b);
	}
	return (0);
}
