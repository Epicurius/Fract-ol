/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 06:19:19 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/23 13:05:52 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <pthread.h>

# define WIDTH 1200
# define HEIGHT 1200
# define THREADS 8
# define MAX_ITER 50
# define COLORS 6

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct	s_fract t_fract;

typedef int	(*t_param)(t_fract *f, t_complex c);

typedef struct		s_fract
{
	char			*pic;
	void			*mlx;
	void			*win;
	void			*img;
	int				menu;
	int				endian;
	int				colors;
	int				**color;
	int				formula;
	int				max_iter;
	int				size_line;
	int 			thread_end;
	int				lock_julia;
	int				thread_index;
	int				thread_start;
	int				**thread_data;
	int				bits_per_pixel;
	double			n;
	double			k[2];
	double 			zoom;
	double			zn[2];
	double			max[2];
	double			min[2];
	t_param			param;
}					t_fract;

int					julia(t_fract *f, t_complex c);
int					key_press(int key, t_fract *f);
int					julia_mod(t_fract *f, t_complex c);
int					mandel_brot(t_fract *f, t_complex c);
int					julia_move(int x, int y, t_fract *f);
int					burning_ship(t_fract *f, t_complex c);
int					zoom(int key, int x, int y, t_fract *f);

void				ui(t_fract *f);
void				redraw(t_fract *f);
void				error_msg(char *str);
void				thread_image(t_fract *f);
void				move(int key, t_fract *f);
void				*draw_fractal(void *f_ptr);
void				color_array(t_fract *f, int malloc);
void				check_fractal(t_fract *f, char *av);
void				color_and_pixel(long double iteration, t_fract *f, int x, int y);

#endif
