/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 19:58:58 by telain            #+#    #+#             */
/*   Updated: 2016/10/01 03:15:51 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	find_side(t_env *e, double ray_x, double ray_y)
{
	if ((int)e->prev_rayx < (int)ray_x)
		e->side = 0xffffff;
	else if ((int)e->prev_rayx > (int)ray_x)
		e->side = 0xff0000;
	else if ((int)e->prev_rayy < (int)ray_y)
		e->side = 0x00ff00;
	else if ((int)e->prev_rayy > (int)ray_y)
		e->side = 0x00ffff;
}

void	get_pixel_color(t_env *e, int x, int y)
{
	e->data[y * e->sl + x * e->bpp / 8] = e->sky_img[(y + 150) *
		(int)SKY_W * 4 +
		(x + (int)(e->angle * (int)SKY_W / 360)) * e->bpp / 8];
	e->data[(y * e->sl + x * e->bpp / 8) + 1] = e->sky_img[(y + 150) *
		(int)SKY_W * 4 +
		(x + (int)(e->angle * (int)SKY_W / 360)) * e->bpp / 8 + 1];
	e->data[(y * e->sl + x * e->bpp / 8) + 2] = e->sky_img[(y + 150) *
		(int)SKY_W * 4 +
		(x + (int)(e->angle * (int)SKY_W / 360)) * e->bpp / 8 + 2];
}

void	draw_line(t_env *e, int x)
{
	int				height;
	int				i;

	i = 0;
	if (e->dist_ray <= 0)
	{
		e->dist_ray = 0.01;
		e->side = 0x0000ff;
	}
	fog(e);
	height = 277 / e->dist_ray;
	while (i < (double)WIN_Y / 2.0 - (double)height / 2.0)
		get_pixel_color(e, x, i++);
	while (i < (double)WIN_Y / 2.0 + (double)height / 2.0)
		pixel_put(e, x, i++, e->fog);
	while (i < WIN_Y - 1)
	{
		pixel_put(e, x, i, find_ground_color(e, i, x));
		i++;
	}
}

void	raycast(t_env *e, double diff_x, double diff_y)
{
	double	ray_x;
	double	ray_y;

	ray_x = e->pos[0];
	ray_y = e->pos[1];
	while ((e->map[(int)(ray_y + diff_y)][(int)(ray_x + diff_x)]
			&& e->map[(int)ray_y][(int)ray_x] == '0') ||
		(e->map[(int)(ray_y + diff_y)][(int)(ray_x + diff_x)]
			&& e->map[(int)ray_y][(int)ray_x] == '2' && e->xray == 1))
	{
		ray_x += diff_x;
		ray_y += diff_y;
	}
	e->hit_x = (int)ray_x;
	e->hit_y = (int)ray_y;
	e->prev_rayx = ray_x - 2 * diff_x;
	e->prev_rayy = ray_y - 2 * diff_y;
	find_side(e, ray_x, ray_y);
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
		raycast(e, cos(DEG_TO_RAD(e->ray_angle)) / 1000,
				sin(DEG_TO_RAD(e->ray_angle)) / 1000);
		e->side = e->map[e->hit_y][e->hit_x] == '2' && e->xray == 0 ?
			shade(e->side) : e->side;
		draw_line(e, col++);
		e->ray_angle += 60 / (double)WIN_X;
	}
}
