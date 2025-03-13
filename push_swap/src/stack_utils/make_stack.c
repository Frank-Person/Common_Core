/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:59:25 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:14:03 by mrapp-he         ###   ########.fr       */
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

t_lst	*build_stack(char **args)
{
	t_lst	*head;
	long	number;

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
