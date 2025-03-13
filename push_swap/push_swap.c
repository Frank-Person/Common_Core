/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:47:08 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/10 18:36:13 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int moves = 0;

static void	print_stack(t_list *stack)
{
	if (stack)
	{		
		printf("node: %d, index: %d\n", stack->content, stack->index);
		print_stack(stack->next);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
  t_list  *stack_b;

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

