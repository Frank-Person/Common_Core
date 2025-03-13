/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:47:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/13 13:12:29 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

extern int	moves;

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}	t_lst;

int		ft_lstsize(t_lst *list);
int		check_doubles(t_lst *stack);
int		stack_sorted(t_lst *stack);
t_lst	*ft_lstnew(int content);
t_lst	*ft_lstlast(t_lst *list);
t_lst	*build_stack(char **args);
t_lst	*ft_lst_bflast(t_lst *list);
void	ft_lstclear(t_lst **list);
void	assign_indexes(t_lst *stack);
void	sort_to_3(t_lst **stack_a);
void	sort_to_4(t_lst **stack_a, t_lst *stack_b);
void	sort_to_5(t_lst **stack_a, t_lst *stack_b);
void	ft_lstadd_back(t_lst **list, t_lst *new_node);
void	op_swap(t_lst **stack, char name, int check);
void	op_rotate(t_lst **stack, char name, int check);
void	op_rev_rotate(t_lst **stack, char name, int check);
void	op_push(t_lst **src_stack, t_lst **dst_stack, char name);
void	two_op(void (*f)(t_lst **, char, int), t_lst **a, t_lst **b, char op);

#endif
