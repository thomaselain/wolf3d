/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:23:50 by telain            #+#    #+#             */
/*   Updated: 2016/08/14 17:47:55 by telain           ###   ########.fr       */
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
# define WIN_X 60
# define WIN_Y 40
# define FOV 60
# define DEG_TO_RAD(X) (X * (M_PI / 180))
# define RAD_TO_DEG(X) (X / (M_PI / 180))
# define GRID(X) (X / 64)

typedef struct	s_env
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*data;
	char	**map;
	char	*map_name;
	int		map_size_x;
	int		map_size_y;
	int		bpp;
	int		sl;
	int		endi;
	int		pos[2];
	double	angle;
	int		diff_vx;
	int		diff_vy;
	int		diff_hx;
	int		diff_hy;
	int		hx;
	int		hy;
	int		vx;
	int		vy;
	int		vert_dist;
	int		hori_dist;
}				t_env;

/*
**	data_init.c
*/

void		new_env(t_env *e, char *av);
void		load_map(t_env *e);
char		*load_line(char *line, int size);

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

int			find_vert_inter(t_env *e);
int			find_hori_inter(t_env *e);
void		scan(t_env *e);
void		raycast(t_env *e);

/*
**	print_map.c
*/

void		print_map(t_env *e, int x, int y);

#endif
