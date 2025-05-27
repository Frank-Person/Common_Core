/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:03:41 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/05/19 18:08:58 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int	malloc_error(void)
{
	write(2, "Malloc Error!\n", 14);
	return (1);
}

int	win_malloc_error(void)
{
	mlx_destroy_display(db()->mlx);
	return (free(db()->mlx), malloc_error());
}

int	img_malloc_error(void)
{
	mlx_clear_window(db()->mlx, db()->win);
	return (win_malloc_error());
}

int	input_error(void)
{
	write(2, "Error: Invalid input\n", 22);
	write(2, "Usage: ./fractol <fractal_name> [max_iter] [width height]\n", 59);
	write(2, "Available fractals:\n", 21);
	write(2, "  - mandelbrot\n", 16);
	write(2, "  - burning\n", 13);
	write(2, "  - julia [regular inputs] {re im}\n", 36);
	write(2, "Examples:\n", 11);
	write(2, "  ./fractol mandelbrot 1000 800 600\n", 37);
	write(2, "  ./fractol burning 500 1024 768\n", 34);
	write(2, "  ./fractol julia 1000 800 600 -0.8 0.156\n", 43);
	return (1);
}
