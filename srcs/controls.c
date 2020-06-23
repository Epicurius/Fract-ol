/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 08:23:50 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 12:43:27 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			julia_move(int x, int y, t_fract *f)
{
	if (f->lock_julia == 0)
	{
		f->k[0] = 2 * ((double)x / WIDTH - 0.5);
		f->k[1] = 2 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		f->win ? mlx_clear_window(f->mlx, f->win) : 0;
		redraw(f);
	}
	return (0);
}

int			zoom(int key, int x, int y, t_fract *f)
{
	double x_offset;
	double y_offset;
	double zoom;

	if (key == 3)
		f->lock_julia = f->lock_julia == 1 ? 0 : 1;
	else if (key == 4 || key == 5)
	{
		zoom = key == 4 ? 1.25 : 0.8333;
		x_offset = ((double)x /
				(WIDTH / (f->max[0] - f->min[0])) + f->min[0]);
		y_offset = ((double)y /
				(HEIGHT / (f->max[1] - f->min[1])) * -1 + f->max[1]);
		f->min[0] = x_offset + ((f->min[0] - x_offset) * zoom);
		f->min[1] = y_offset + ((f->min[1] - y_offset) * zoom);
		f->max[0] = x_offset + ((f->max[0] - x_offset) * zoom);
		f->max[1] = y_offset + ((f->max[1] - y_offset) * zoom);
		redraw(f);
	}
	return (0);
}

void		move(int key, t_fract *f)
{
	double offset[2];

	offset[0] = FT_ABS(f->max[0] - f->min[0]);
	offset[1] = FT_ABS(f->max[1] - f->min[1]);
	if (key == 123 || key == 124)
	{
		f->min[0] += (key == 124 ? -(offset[0]) : offset[1]) * 0.05;
		f->max[0] += (key == 124 ? -(offset[0]) : offset[1]) * 0.05;
	}
	else if (key == 125 || key == 126)
	{
		f->min[1] += (key == 125 ? -(offset[1]) : offset[1]) * 0.05;
		f->max[1] += (key == 125 ? -(offset[1]) : offset[1]) * 0.05;
	}
}

int			key_press(int key, t_fract *f)
{
	if (key == 53)
		exit(1);
	else if (key == 15)
		f->formula += f->formula < 11 ? 1 : -10;
	else if (key == 49)
		color_array(f, 0);
	else if (key == 34 || key == 31)
		f->max_iter += key == 34 ? 2 : -2;
	else if (key == 46)
		f->n += (f->n * f->n) < 16 ? 1 : -3;
	else if (key == 38)
		f->lock_julia = f->lock_julia == 1 ? 0 : 1;
	else if (key == 13 || key == 1)
	{
		f->max_iter += key == 4 ? -2 : 2;
		f->min[0] = (f->min[0] * (key == 13 ? 1.25 : 0.8333));
		f->min[1] = (f->min[1] * (key == 13 ? 1.25 : 0.8333));
		f->max[0] = (f->max[0] * (key == 13 ? 1.25 : 0.8333));
		f->max[1] = (f->max[1] * (key == 13 ? 1.25 : 0.8333));
	}
	else
		move(key, f);
	key == 4 ? f->menu *= -1 : 0;
	redraw(f);
	return (0);
}
