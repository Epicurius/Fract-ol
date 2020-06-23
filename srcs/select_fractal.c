/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 11:03:28 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 12:21:16 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	check_fractal(t_fract *f, char *av)
{
	f->colors = COLORS;
	if (ft_strequ(av, "julia"))
		f->param = julia;
	else if (ft_strequ(av, "mandel_brot"))
		f->param = mandel_brot;
	else if (ft_strequ(av, "julia_mod"))
		f->param = julia_mod;
	else if (ft_strequ(av, "burning_ship"))
		f->param = burning_ship;
	else
		error_msg("Error: Not valid fractal name.\n");
}
