/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:59:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/06 11:43:05 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_doubles(t_list *stack)
{
	t_list	*current;
	t_list	*next_one;

	current = stack;
	while (current && current->next)
	{
		next_one = current->next;
		while (next_one && next_one->next)
		{
			if (current->content == next_one->content)
				return (1);
			next_one = next_one->next;
		}
		current = current->next;
	}
	return (0);
}

