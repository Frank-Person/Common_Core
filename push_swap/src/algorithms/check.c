/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:46:55 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/11 17:54:35 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void  check_algorithm(t_list **stack_a, t_list **stack_b)
{
  int size;

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

