/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:23:50 by telain            #+#    #+#             */
/*   Updated: 2016/08/20 17:14:30 by telain           ###   ########.fr       */
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
# define WIN_X 800
# define WIN_Y 500
# define SKY_FILE "images/sky.xpm"
# define SKY_W 1836
# define SKY_H 500
# define FOV 60
# define DEG_TO_RAD(X) (X * (M_PI / 180))
# define RAD_TO_DEG(X) (X / (M_PI / 180))
# define GRID(X) (X / 64)

typedef struct	s_env
{
	void	*win;
	void	*mlx;
	void	*img;
	void	*sky;
	char	*sky_img;
	char	*data;
	char	**map;
	char	*map_name;
	int		map_size_x;
	int		map_size_y;
	int		bpp;
	int		sl;
	int		endi;
	int		angle;
	int		case_hit_x;
	int		case_hit_y;
	int		sky_pixel;
	double	pos[2];
	double	ray_angle;
	double	dist_ray;
	double	move_x;
	double	speed;
	double	move_y;
	double	prev_ray_x;
	double	prev_ray_y;
	int		side;
	double	fog_dist;
	int		fog;
	int		ground_color;
}				t_env;

/*
**	main.c
*/

int		destroy(int key, void *e);

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
int			find_ground_color(t_env *e, double x, double y);

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
void		move(t_env *e);

/*
**	raycast.c
*/

void		get_pixel_color(t_env *e, int x, int y);
void		init_raycast(t_env *e);
void		raycast(t_env *e);
void		scan(t_env *e);

/*
**	print_map.c
*/

void		print_map(t_env *e, int x, int y);

#endif
