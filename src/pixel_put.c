/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:41:21 by telain            #+#    #+#             */
/*   Updated: 2016/10/01 03:13:41 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		shade(int c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = ((c >> 16) & 0xff) * 0.5;
	g = ((c >> 8) & 0xff) * 0.5;
	b = (c & 0xff) * 0.5;
	return ((r << 16) + (g << 8) + b);
}

void	pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;

	new_color = mlx_get_color_value(e->mlx, color);
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		e->data[y * e->sl + x * e->bpp / 8] = (new_color & 0xff);
		e->data[y * e->sl + x * e->bpp / 8 + 1] = (new_color & 0xff00) >> 8;
		e->data[y * e->sl + x * e->bpp / 8 + 2] = (new_color & 0xff0000) >> 16;
	}
}

int		find_ground_color(t_env *e, double x, double y)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	dist;

	dist = sqrt(((double)(WIN_X) - x) * ((double)(WIN_X) - x) +
			((double)(WIN_Y) - y) * ((double)(WIN_Y) - y)) / e->fog_dist;
	r = dist < e->fog_dist * 2 ? ((e->ground_color >> 16) & 0xff) *
		dist / -e->fog_dist / 2 : 0;
	g = dist < e->fog_dist * 2 ? ((e->ground_color >> 8) & 0xff) *
		dist / -e->fog_dist / 2 : 0;
	b = dist < e->fog_dist * 2 ? (e->ground_color & 0xff) * dist /
		-e->fog_dist / 2 : 0;
	return ((r << 16) + (g << 8) + b);
}

void	fog(t_env *e)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = e->dist_ray < e->fog_dist ?
		((e->side >> 16) & 0xff) * e->dist_ray / -e->fog_dist : 0;
	g = e->dist_ray < e->fog_dist ?
		((e->side >> 8) & 0xff) * e->dist_ray / -e->fog_dist : 0;
	b = e->dist_ray < e->fog_dist ?
		(e->side & 0xff) * e->dist_ray / -e->fog_dist : 0;
	e->fog = (r << 16) + (g << 8) + b;
	e->fog = (e->dist_ray < 0.1 && e->side == 0xffffff) ? 0xffffff : e->fog;
	e->fog = (e->dist_ray < 0.1 && e->side == 0xff0000) ? 0xff0000 : e->fog;
}
