/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:05:46 by telain            #+#    #+#             */
/*   Updated: 2016/08/20 17:35:43 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	get_pixel_color(t_env *e, int x, int y)
{
	e->data[y * e->sl + x * e->bpp / 8] =
		e->sky_img[(y + 150) * SKY_W * 4 +
		(x + (int)(e->angle * SKY_W / 360)) * e->bpp / 8];
	e->data[(y * e->sl + x * e->bpp / 8) + 1] =
		e->sky_img[(y + 150) * SKY_W * 4 +
		(x + (int)(e->angle * SKY_W / 360)) * e->bpp / 8 + 1];
	e->data[(y * e->sl + x * e->bpp / 8) + 2] =
		e->sky_img[(y + 150) * SKY_W * 4 +
		(x + (int)(e->angle * SKY_W / 360)) * e->bpp / 8 + 2];
}

void	draw_line(t_env *e, int col)
{
	int				height;
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	i = 0;
	r = e->dist_ray < e->fog_dist ?
		((e->side >> 16) & 0xff) * e->dist_ray / -e->fog_dist : 0;
	g = e->dist_ray < e->fog_dist ?
		((e->side >> 8 ) & 0xff) * e->dist_ray / -e->fog_dist : 0;
	b = e->dist_ray < e->fog_dist ?
		(e->side & 0xff) * e->dist_ray / -e->fog_dist : 0;
	e->fog = (r << 16) + (g << 8) + b;
	e->fog = (e->dist_ray < 0.1 && e->side == 0xffffff) ? 0xffffff : e->fog;
	e->fog = (e->dist_ray < 0.1 && e->side == 0xff0000) ? 0xff0000 : e->fog;
	height = 277 / e->dist_ray;
	while (i < (double)WIN_Y / 2.0 - (double)height / 2.0)
		get_pixel_color(e, col, i++);
	while (i < (double)WIN_Y / 2.0 + (double)height / 2.0)
		pixel_put(e, col, i++, e->fog);
	while (i < WIN_Y - 1)
	{
		pixel_put(e, col, i, find_ground_color(e, i, col));
		i++;
	}
}

void	raycast(t_env *e)
{
	int		hit;
	double	ray_x;
	double	ray_y;
	double	diff_x;
	double	diff_y;

	diff_x = cos(DEG_TO_RAD(e->ray_angle)) / 1000;
	diff_y = sin(DEG_TO_RAD(e->ray_angle)) / 1000;
	ray_x = e->pos[0];
	ray_y = e->pos[1];
	hit = 0;
	while (hit == 0)
	{
		if (!e->map[(int)(ray_y + diff_y)][(int)(ray_x + diff_x)]
				|| e->map[(int)ray_y][(int)ray_x] != '0')
			hit = 1;
		else
		{
			ray_x += diff_x;
			ray_y += diff_y;
		}
	}
	e->case_hit_x = (int)ray_x;
	e->case_hit_y = (int)ray_y;
	e->prev_ray_x = ray_x - 2 * diff_x;
	e->prev_ray_y = ray_y - 2 * diff_y;
	e->side =  ((int)e->prev_ray_x < (int)ray_x ||
			(int)e->prev_ray_x > (int)ray_x || ray_x == (int)ray_x
			|| ray_y == (int)ray_y) ? 0xffffff : 0xff0000;
	e->dist_ray = sqrt((e->pos[0] - ray_x) * (e->pos[0] - ray_x) +
			(e->pos[1] - ray_y) * (e->pos[1] - ray_y)) *
		cos(DEG_TO_RAD(e->angle) - DEG_TO_RAD(e->ray_angle));
}

void	scan(t_env *e)
{
	int		col;

	col = 0;
	e->angle = (e->angle < 0) ? e->angle += 360 : e->angle % 360;
	e->ray_angle = e->angle - 30;
	while (col < WIN_X)
	{
		raycast(e);
		e->ray_angle += 60 / (double)WIN_X;
		draw_line(e, col++);
	}
	e->ray_angle = e->angle;
	raycast(e);
	print_map(e, e->case_hit_x, e->case_hit_y);
}
