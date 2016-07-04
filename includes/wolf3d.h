/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:23:50 by telain            #+#    #+#             */
/*   Updated: 2016/07/04 16:45:24 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdio.h>
# include "keys.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# define WIN_X 600
# define WIN_Y 480
# define FOV 60

typedef struct	s_env
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*data;
	char	**map;
	int		map_size_x;
	int		map_size_y;
	int		bpp;
	int		sl;
	int		endi;
	double	pos[2];
	double	angle;
}				t_env;

/*
**	data_init.c
*/

void		new_env(t_env *e);
void		load_map(t_env *e);

/*
**	display.c
*/

void		display_error(int error);

/*
**	pixel_put.c
*/

void		pixel_put(t_env *e, int x, int y, int color);		

/*
**	draw_window.c
*/

void		draw_window(t_env *e);
int			refresh(int key, void *e);

/*
**	inputs.c
*/

int			find_key(int key, void *e);
int			expose_find_key(int key, void *e);
void		do_input(t_env *e, int key);

/*
**	raycast.c
*/

int			find_first_inter(t_env *e);
void		scan(t_env *e);

#endif
