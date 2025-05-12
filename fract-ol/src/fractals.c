/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:43:35 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/30 18:31:25 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

int		iterations(t_complex z, t_complex c, int max_iter)
{
	int	  iter;

	iter = -1;
	while (magnitude_squared(z) <= 4 && ++iter < max_iter)
		z = add_complex(square_complex(z), c);
	return (iter);
}

void	draw_mandelbrot(int x, int y, int max_iter)
{
	int	  iter;
	int	  color;
	int	  temp[2];

	temp[0] = x;
	temp[1] = y;
	db()->z = new_complex(0, 0);
	db()->c = screen_to_complex(temp[0], temp[1], db()->min_re, db()->max_re, db()->min_im, db()->max_im);
	iter = iterations(db()->z, db()->c, max_iter);
	color = generate_color(iter, max_iter);
	put_pixel(temp[0], temp[1], color);
}

void	draw_julia(int x, int y, int max_iter)
{
	int	  iter;
	int	  color;
	int	  temp[2];

	temp[0] = x;
	temp[1] = y;
	db()->z = screen_to_complex(temp[0], temp[1], db()->min_re, db()->max_re, db()->min_im, db()->max_im);
	iter = iterations(db()->z, db()->c, max_iter);
	color = generate_color(iter, max_iter);
	put_pixel(temp[0], temp[1], color);
}
