/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 09:57:34 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 11:50:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		mandel_brot(t_fract *f, t_complex c)
{
	t_complex	z;
	t_complex	s;
	int			iteration;

	iteration = 0;
	z.re = 0.0;
	z.im = 0.0;
	s.re = 0.0;
	s.im = 0.0;
	while ((s.re + s.im) <= f->n && iteration < f->max_iter)
	{
		z.im = 2.0 * (z.im * z.re) + c.im;
		z.re = s.re - s.im + c.re;
		s.re = z.re * z.re;
		s.im = z.im * z.im;
		iteration++;
	}
	f->zn[0] = z.re;
	f->zn[1] = z.im;
	return (iteration);
}

int		julia_mod(t_fract *f, t_complex c)
{
	t_complex	z;
	t_complex	s;
	int			iteration;

	iteration = 0;
	z.re = c.re;
	z.im = c.im;
	s.re = c.re * c.re;
	s.im = c.im * c.im;
	while ((s.re + s.im) <= f->n && iteration < f->max_iter)
	{
		z.im = 2 * FT_ABS(z.im * z.re) + f->k[1];
		z.re = FT_ABS(s.re - s.im) + f->k[0];
		s.re = z.re * z.re;
		s.im = z.im * z.im;
		iteration++;
	}
	f->zn[0] = z.re;
	f->zn[1] = z.im;
	return (iteration);
}

int		julia(t_fract *f, t_complex c)
{
	t_complex	z;
	t_complex	s;
	int			iteration;

	iteration = 0;
	z.re = c.re;
	z.im = c.im;
	s.re = c.re * c.re;
	s.im = c.im * c.im;
	while ((s.re + s.im) <= f->n && iteration < f->max_iter)
	{
		z.im = 2 * (z.im * z.re) + f->k[1];
		z.re = s.re - s.im + f->k[0];
		s.re = z.re * z.re;
		s.im = z.im * z.im;
		iteration++;
	}
	f->zn[0] = z.re;
	f->zn[1] = z.im;
	return (iteration);
}

int		burning_ship(t_fract *f, t_complex c)
{
	t_complex	z;
	t_complex	s;
	int			iteration;

	iteration = 0;
	z.re = 0.0;
	z.im = 0.0;
	s.re = 0.0;
	s.im = 0.0;
	while (s.re + s.im <= f->n && iteration < f->max_iter)
	{
		z.im = FT_ABS(-2.0 * (z.im * z.re) + c.im);
		z.re = FT_ABS(s.re - s.im + c.re);
		s.re = z.re * z.re;
		s.im = z.im * z.im;
		iteration++;
	}
	f->zn[0] = z.re;
	f->zn[1] = z.im;
	return (iteration);
}
