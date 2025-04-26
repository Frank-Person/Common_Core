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

#include "../../lib/push_swap.h"

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
	while (*alpha[0] >= '0' && *alpha[0] <= '9'
		&& !(num * sgn > INT_MAX || num * sgn < INT_MIN))
		num = (num * 10) + (*alpha[0]++ - '0');
	if (num * sgn > INT_MAX || num * sgn < INT_MIN)
		*alpha[0] = 'e';
	return (num * sgn);
}

t_lst	*build_stack(char **args)
{
	static int	error;
	t_lst		*head;
	long		number;

	if (!args || !*args)
		return (NULL);
	head = NULL;
	if (!*args[0])
		error++;
	number = ft_atol(args);
	if (*args[0] == '\0')
		args++;
	else if (*args[0] != ' ')
		error++;
	head = ft_lstnew(number);
	if (head && !error)
		head->next = build_stack(args);
	if (error)
		return (free(head), NULL);
	return (head);
}
