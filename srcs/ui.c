/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 15:37:07 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 13:02:29 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ui(t_fract *f)
{
	int		w;
	char	*num;

	if (f->menu == -1)
		return ;
	w = WIDTH - 250;
	mlx_string_put(f->mlx, f->win, w, 20, 0x00FF00, "Move: Arrow / mouse");
	mlx_string_put(f->mlx, f->win, w, 40, 0x00FF00, "Color: Space bar");
	mlx_string_put(f->mlx, f->win, w, 60, 0x00FF00, "Iter: I / O");
	mlx_string_put(f->mlx, f->win, w, 80, 0x00FF00, "Julia lock: Scroll key");
	mlx_string_put(f->mlx, f->win, w, 100, 0x00FF00, "Zoom: Scroll wheel");
	mlx_string_put(f->mlx, f->win, w, 120, 0x00FF00, "Move julia: Mouse");
	mlx_string_put(f->mlx, f->win, w, 140, 0x00FF00, "LSD: R");
	mlx_string_put(f->mlx, f->win, w, 160, 0x00FF00, "Change: m");
	mlx_string_put(f->mlx, f->win, w, 180, 0x00FF00, "Iter: ");
	num = ft_itoa(f->max_iter);
	mlx_string_put(f->mlx, f->win, w + 60, 180, 0x00FF00, num);
	ft_strdel(&num);
}
