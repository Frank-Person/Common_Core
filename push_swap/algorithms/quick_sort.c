/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:49:43 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/04 15:58:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*quick_sort(t_list **stack)
{
	t_list	*dummy_node;
	t_list	*pivot;

	dummy_node->next = (*stack);
	pivot = ft_lstlast(*stack);
	
}