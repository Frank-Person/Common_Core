/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:59:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/08 15:10:34 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static long	ft_atol(char **alpha)
{
	long	num;
	long	sgn;

	num = 0;
	while (*alpha[0] == ' ' || (*alpha[0] >= '\t' && *alpha[0] <= '\r'))
		alpha[0]++;
	sgn = (*alpha[0] != '-') - (*alpha[0] == '-');
	if (*alpha[0] == '+' || *alpha[0] == '-')
		alpha[0]++;
	while (*alpha[0] >= '0' && *alpha[0] <= '9')
		num = (num * 10) + (*alpha[0]++ - '0');
	if (num * sgn > 2147483647 || num * sgn < -2147483648)
		*alpha[0] = 'e';
  return (num * sgn);
}

static int partition(int *array, int start, int end)
{
  int i;
  int j;
  int temp;
  int pivot;

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

static void quick_sort(int *array, int start, int end)
{
  int pi;

  pi = 0;
  if (start < end)
  {
    pi = partition(array, start, end);
    quick_sort(array, start, pi - 1);
    quick_sort(array, pi + 1, end);
  }
}

void  assign_indexes(t_list *stack)
{
  int     i;
  int     size;
  int     *array;
  t_list  *current;

  i = 0;
  size = ft_lstsize(stack);
  array = malloc(size * sizeof(int));
  if (!array)
    return ;
  current = stack;
  while (current)
  {
    array[i++] = current->content;
    current = current->next;
  }
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

t_list	*build_stack(char **args)
{
	t_list	*head;
	long	number;;

	if (!*args)
		return (NULL);
	head = NULL;
	number = ft_atol(args);
	if (*args[0] == '\0')
		args++;
	else if (*args[0] != ' ')
		exit(write(2, "Error\n", 6));
	head = ft_lstnew(number);
	if (head)
		head->next = build_stack(args);
	return (head);
}

