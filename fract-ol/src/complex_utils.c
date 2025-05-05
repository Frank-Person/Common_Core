/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 06:59:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/18 07:42:36 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

t_complex	new_complex(double re, double im)
{
	t_complex	new;

	new.re = re;
	new.im = im;
	return (new);
}

t_complex	add_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.re = z.re + c.re;
	result.im = z.im + c.im;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}

t_complex	screen_to_complex(int x, int y, double min_re, double max_re, double min_im, double max_im)
{
	t_complex	result;

	result.re = min_re + (x / (double)WIDTH) * (max_re - min_re);
	result.im = max_im - (y / (double)HEIGHT) * (max_im - min_im);
	return (result);
}

double	magnitude_squared(t_complex z)
{
return (z.re * z.re + z.im * z.im);
}
