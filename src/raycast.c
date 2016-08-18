/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:05:46 by telain            #+#    #+#             */
/*   Updated: 2016/08/18 02:41:21 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	draw_line(t_env *e, int col)
{
	int		height;
	int		i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	i = 0;
	r = e->dist_ray < 15 ? ((e->side >> 16) & 0xff) * e->dist_ray / 15 : 0;
	g = e->dist_ray < 15 ? ((e->side >> 8 ) & 0xff) * e->dist_ray / 15 : 0;
	b = e->dist_ray < 15 ? (e->side & 0xff) * e->dist_ray / 15 : 0;
	e->fog = (r << 16) + (g << 8) + b;
	height = 277 / e->dist_ray;
	if (e->dist_ray == 0)
		height = WIN_Y;
	while (i < (double)WIN_Y / 2.0 - (double)height / 2.0)
		pixel_put(e, col, i++, 0x303030);
	while (i < (double)WIN_Y / 2.0 + (double)height / 2.0)
			pixel_put(e, col, i++, -e->fog);
	while (i < WIN_Y - 1)
		pixel_put(e, col, i++, 0x101010);
}

void	raycast(t_env *e)
{
	int		hit;
	double	ray_x;
	double	ray_y;
	double	diff_x;
	double	diff_y;

	diff_x = cos(DEG_TO_RAD(e->ray_angle)) / 2000;
	diff_y = sin(DEG_TO_RAD(e->ray_angle)) / 2000;
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
	e->prev_ray_x = e->ray_hit_x - 2 * diff_x;
	e->prev_ray_y = e->ray_hit_y - 2 * diff_y;
	e->ray_hit_x = (int)ray_x;
	e->ray_hit_y = (int)ray_y;
	e->side = 0xff0000;
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
	printf("angle : %d\ncos(angle + 90) : %f\t\tsin(angle + 90) : %f\n", e->angle, cos(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90)), sin(DEG_TO_RAD(e->angle + 90) + DEG_TO_RAD(90)));
	printf("truc : %d", (int)((double)(1 + 1)));
	e->ray_angle = e->angle;
	raycast(e);
	print_map(e, e->ray_hit_x, e->ray_hit_y);
}
