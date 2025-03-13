/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:25:13 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:18:11 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	partition(int *array, int start, int end)
{
	int	i;
	int	j;
	int	temp;
	int	pivot;

	i = start - 1;
	j = start;
	pivot = array[end];
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}

static void	quick_sort(int *array, int start, int end)
{
	int	pi;

	pi = 0;
	if (start < end)
	{
		pi = partition(array, start, end);
		quick_sort(array, start, pi - 1);
		quick_sort(array, pi + 1, end);
	}
}

static int	*fill_array(t_lst *stack, int size)
{
	int		i;
	int		*array;
	t_lst	*current;

	i = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	current = stack;
	while (current)
	{
		array[i++] = current->content;
		current = current->next;
	}
	return (array);
}

void	assign_indexes(t_lst *stack)
{
	int		i;
	int		size;
	int		*array;
	t_lst	*current;

	size = ft_lstsize(stack);
	array = fill_array(stack, size);
	quick_sort(array, 0, size - 1);
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->content == array[i++])
			{
				current->index = i - 1;
				break ;
			}
		}
		current = current->next;
	}
	free(array);
}
