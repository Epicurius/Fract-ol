/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:14:46 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 12:43:17 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

long double		which_formula(t_fract *f, int x)
{
	long double znz;

	if (x == 1)
		znz = sqrt((f->zn[0] * f->zn[0]) + (f->zn[1] * f->zn[1]));
	else if (x == 2)
		znz = (exp(f->zn[0] * f->zn[0]) * exp(f->zn[1] * f->zn[1]));
	else if (x == 3)
		znz = ((f->zn[0] * f->zn[0]) / (f->zn[1] * f->zn[1]));
	else if (x == 4)
		znz = ((f->zn[0] * f->zn[0]) + (f->zn[1] * f->zn[1]));
	else if (x == 5)
		znz = ((f->zn[0] * f->zn[0]) - (f->zn[1] * f->zn[1]));
	else if (x == 6)
		znz = pow(f->zn[0], 0.05) + pow(f->zn[1], 0.5);
	else if (x == 7)
		znz = pow(f->zn[0], 3.0) + pow(f->zn[1], 3.0);
	else if (x == 8)
		znz = (f->zn[0] * log(3)) + (f->zn[1] * log(3));
	else if (x == 9)
		znz = tan((f->zn[0] * f->zn[0]) + (f->zn[1] * f->zn[1]));
	else if (x == 10)
		znz = tan((f->zn[0] * f->zn[0]) - (f->zn[1] * f->zn[1]));
	else
		znz = exp((f->zn[0] * f->zn[0]) * (f->zn[1] * f->zn[1]));
	return (znz);
}

void			color_and_pixel(long double iteration, t_fract *f, int x, int y)
{
	int		c1;
	int		c2;
	double	i;
	double	t1;
	double	t2;

	if (iteration >= f->max_iter &&
			(f->param == mandel_brot || f->param == burning_ship))
		return ;
	i = iteration - (log(log(which_formula(f, f->formula))) / log(2));
	i = i / f->max_iter * f->colors;
	c1 = (int)i;
	t2 = i - c1;
	t1 = 1 - t2;
	c1 %= f->colors;
	c2 = (c1 + 1) % f->colors;
	c1 *= c1 < 0 ? -1 : 1;
	c2 *= c2 < 0 ? -1 : 1;
	i = (x * f->bits_per_pixel / 8) + (y * f->size_line);
	f->pic[(int)i] = (uint8_t)f->color[c1][0] * t1 + f->color[c2][0] * t2;
	f->pic[(int)++i] = (uint8_t)f->color[c1][1] * t1 + f->color[c2][1] * t2;
	f->pic[(int)++i] = (uint8_t)f->color[c1][2] * t1 + f->color[c2][2] * t2;
}
