/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 06:16:51 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 12:59:53 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		only_num(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] < 48 || str[x] > 57)
			return (0);
		x++;
	}
	return (1);
}

void	init(t_fract *f)
{
	color_array(f, 1);
	f->menu = -1;
	f->formula = 1;
	f->n = 4;
	f->max_iter = MAX_ITER;
	f->zoom = 0.0;
	f->lock_julia = 0;
	f->min[0] = -2.0;
	f->min[1] = -2.0;
	f->max[0] = 2.0;
	f->max[1] = f->min[1] + (f->max[0] - f->min[0]) * HEIGHT / WIDTH;
	if (f->param == julia_mod)
	{
		f->k[0] = 0.285000;
		f->k[1] = 0.003333;
	}
	else
	{
		f->k[0] = 0.490000;
		f->k[1] = 0.000000;
	}
}

int		main(int ac, char **av)
{
	t_fract	*f;

	f = (t_fract *)malloc(sizeof(*f));
	ac < 2 ? error_msg(NULL) : 0;
	check_fractal(f, av[1]);
	if (ac == 3)
	{
		only_num(av[2]) == 0 ? error_msg("Error: color_amount.\n") : 0;
		f->colors = ft_atoi(av[2]);
		f->colors == 0 ? error_msg("Error: Color_amount can't be 0.\n") : 0;
	}
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, av[1]);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->pic = mlx_get_data_addr(f->img, &(f->bits_per_pixel),
			&(f->size_line), &(f->endian));
	init(f);
	thread_image(f);
	mlx_hook(f->win, 2, 2, key_press, f);
	mlx_hook(f->win, 4, 0, zoom, f);
	mlx_hook(f->win, 6, 0, julia_move, f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	ui(f);
	mlx_loop(f->mlx);
	return (0);
}
