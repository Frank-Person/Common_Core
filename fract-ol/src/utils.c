/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:13:43 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/04 12:18:01 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	  i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	check_next_pos(int x, int y)
{
	t_complex position;

	position = new_complex(x, y);
	return (magnitude_squared(position));
}
