/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:52:22 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/15 18:21:07 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int file_descriptor)
{
	long	number;
	char	character;

	number = n;
	if (number < 0)
	{
		number = -number;
		write(file_descriptor, "-", 1);
	}
	if (number > 9)
		ft_putnbr_fd((number / 10), file_descriptor);
	character = (number % 10) + '0';
	write(file_descriptor, &character, 1);
}
