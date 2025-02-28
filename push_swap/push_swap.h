/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:47:05 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/02/28 01:56:03 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
int		stack_sorted(t_list *stack);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lst_bflast(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	op_swap(t_list **stack, char name, int check);
void	op_rotate(t_list **stack, char name, int check);
void	op_rev_rotate(t_list **stack, char name, int check);
void	op_push(t_list **src_stack, t_list **dst_stack, char name);
void	double_op(void (*f)(t_list **, char, int), t_list **stack_a, t_list **stack_b, char name);

#endif
