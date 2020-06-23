/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:26:58 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 11:37:37 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		redraw(t_fract *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	thread_image(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	ui(f);
}

void		color_array(t_fract *f, int m)
{
	int y;

	y = 0;
	if (m == 1)
		f->color = (int **)malloc(sizeof(int *) * f->colors);
	while (y < f->colors)
	{
		if (m == 1)
			f->color[y] = (int *)malloc(sizeof(int) * 3);
		f->color[y][0] = rand() % 255;
		f->color[y][1] = rand() % 255;
		f->color[y][2] = rand() % 255;
		y++;
	}
}

void		*draw_fractal(void *f_ptr)
{
	t_fract		*f;
	int			y;
	int			x;
	t_complex	c;

	f = (t_fract*)f_ptr;
	y = f->thread_start;
	while (y < f->thread_end)
	{
		c.im = (f->max[1] - y * (f->max[1] - f->min[1]) / HEIGHT);
		x = 0;
		while (x < WIDTH)
		{
			c.re = (f->min[0] + x * (f->max[0] - f->min[0]) / WIDTH);
			color_and_pixel(f->param(f, c), f, x, y);
			x++;
		}
		y++;
	}
	return (f_ptr);
}
