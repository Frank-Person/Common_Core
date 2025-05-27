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
	double		temp[4];

	temp[0] = z.re;
	temp[1] = z.im;
	temp[2] = c.re;
	temp[3] = c.im;
	result.re = temp[0] + temp[2];
	result.im = temp[1] + temp[3];
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;
	double		temp[2];

	temp[0] = z.re;
	temp[1] = z.im;
	result.re = (temp[0] * temp[0]) - (temp[1] * temp[1]);
	result.im = 2 * temp[0] * temp[1];
	return (result);
}

t_complex	screen_to_complex(int x, int y)
{
	t_data		*dt;
	t_complex	max;
	t_complex	min;
	t_complex	result;

	dt = db();
	max = dt->max;
	min = dt->min;
	result.re = min.re + (x / (double)dt->win_w) * (max.re - min.re);
	result.im = max.im - (y / (double)dt->win_h) * (max.im - min.im);
	return (result);
}

double	magnitude_squared(t_complex z)
{
	double	temp[2];

	temp[0] = z.re;
	temp[1] = z.im;
	return ((temp[0] * temp[0]) + (temp[1] * temp[1]));
}
