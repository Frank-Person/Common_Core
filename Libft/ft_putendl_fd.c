/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:47:58 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/19 13:26:15 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *string, int file_descriptor)
{
	if (!string)
		return ;
	ft_putstr_fd(string, file_descriptor);
	ft_putchar_fd('\n', file_descriptor);
}
