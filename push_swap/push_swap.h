/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:47:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/03/10 18:35:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

extern int moves;

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}	t_list;

int				ft_lstsize(t_list *list);
int				check_doubles(t_list *stack);
int				stack_sorted(t_list *stack);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *list);
t_list		*build_stack(char **args);
t_list		*ft_lst_bflast(t_list *list);
void      ft_lstclear(t_list **list);
void      assign_indexes(t_list *stack);
void			sort_to_3(t_list **stack_a);
void      sort_to_4(t_list **stack_a, t_list *stack_b);
void      sort_to_5(t_list **stack_a, t_list *stack_b);
void      check_algorithm(t_list **stack_a, t_list **stack_b);
void			ft_lstadd_back(t_list **list, t_list *new_node);
void			op_swap(t_list **stack, char name, int check);
void			op_rotate(t_list **stack, char name, int check);
void			op_rev_rotate(t_list **stack, char name, int check);
void			op_push(t_list **src_stack, t_list **dst_stack, char name);
void			double_op(void (*f)(t_list **, char, int), t_list **stack_a, t_list **stack_b, char name);

#endif
