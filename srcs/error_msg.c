/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:25:25 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 13:01:07 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		error_msg(char *str)
{
	ft_putstr(
		"\x1b[32m--------------------------------------------------\n\x1b[31m");
	if (str != NULL)
		ft_putstr(str);
	ft_putstr("\x1b[0m\nPress 'H' to open help menu in window.\n");
	ft_putstr("\nUsage:\n");
	ft_putstr("	./fractol [fractal_name] [color_amount]\n");
	ft_putstr("	Default color_amount set to 6.\n");
	ft_putstr(
		"\nFractals:\n	mandel_brot\n	julia\n	julia_mod\n	burning_ship\n\n");
	ft_putstr(
		"\x1b[32m--------------------------------------------------\n\x1b[0m");
	exit(1);
}
