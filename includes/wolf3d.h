/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:23:50 by telain            #+#    #+#             */
/*   Updated: 2016/10/01 03:17:40 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

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
# define RAD_TO_DEG(X) (X / (M_PI / 180)
# define BLUE 0x0000ff

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	void		*img;
	void		*sky;
	char		*sky_img;
	char		*data;
	char		**map;
	char		*map_name;
	int			map_size_x;
	int			map_size_y;
	int			bpp;
	int			sl;
	int			endi;
	int			angle;
	int			sky_pixel;
	int			hit_x;
	int			hit_y;
	int			xray;
	double		pos[2];
	double		ray_angle;
	double		dist_ray;
	double		move_x;
	double		move_y;
	double		speed;
	double		prev_rayx;
	double		prev_rayy;
	int			side;
	double		fog_dist;
	int			fog;
	int			ground_color;
	int			i;
	int			j;
}				t_env;

/*
**	main.c
*/

int				destroy(int key, void *e);

/*
**	data_init.c
*/

void			new_env(t_env *e, char *av);
void			load_map(t_env *e);
void			load_line(char *line, int size, t_env *e);
void			init_values(t_env *e);

/*
**	display.c
*/

void			display_error(int error, t_env *e);

/*
**	pixel_put.c
*/

void			fog(t_env *e);
void			pixel_put(t_env *e, int x, int y, int color);
int				shade(int c);
int				find_ground_color(t_env *e, double x, double y);

/*
**	draw_window.c
*/

void			clear(t_env *e);
void			draw_window(t_env *e);
int				refresh(int key, void *e);

/*
**	inputs.c
*/

int				find_key(int key, void *e);
int				expose_find_key(int key, void *e);
void			do_input(t_env *e, int key);
void			move(t_env *e);
void			move_inputs(t_env *e, int key);

/*
**	raycast.c
*/

void			get_pixel_color(t_env *e, int x, int y);
void			draw_line(t_env *e, int col);
void			raycast(t_env *e, double diff_x, double diff_y);
void			scan(t_env *e);

#endif
