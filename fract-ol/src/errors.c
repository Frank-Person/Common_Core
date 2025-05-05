/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:03:41 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/03 20:59:08 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	  malloc_error(void)
{
	perror("Malloc Error!\n");
	return (1);
}

int	  win_malloc_error(void)
{
	mlx_destroy_display(db()->mlx);
	return (free(db()->mlx), malloc_error());
}

int	  img_malloc_error(void)
{
	mlx_clear_window(db()->mlx, db()->win);
	return (win_malloc_error());
}

int	  input_error(void)
{
	perror("Input Error!\n");
	return (1);
}
