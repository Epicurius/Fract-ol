/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:24:37 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 11:55:08 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	thread_image(t_fract *f)
{
	pthread_t		threads[THREADS];
	t_fract			thread_f[THREADS];
	int				i;
	int				thread_num;

	thread_num = THREADS == 0 ? 1 : THREADS;
	i = 0;
	while (i < thread_num)
	{
		ft_memcpy((void*)&thread_f[i], (void*)f, sizeof(t_fract));
		thread_f[i].thread_index = i;
		thread_f[i].thread_start = i * (HEIGHT / thread_num);
		thread_f[i].thread_end = (i + 1) * (HEIGHT / thread_num);
		pthread_create(&threads[i], NULL, draw_fractal, &thread_f[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	ui(f);
}
