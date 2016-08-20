/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:41:21 by telain            #+#    #+#             */
/*   Updated: 2016/08/20 17:29:52 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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

	dist = sqrt(((double)(WIN_X) - x) * ((double)(WIN_X) - x) + ((double)(WIN_Y) - y)
			* ((double)(WIN_Y) - y)) / e->fog_dist;
	r = dist < e->fog_dist * 2 ? ((e->ground_color >> 16) & 0xff) * dist / -e->fog_dist / 2 : 0;
	g = dist < e->fog_dist * 2 ? ((e->ground_color >> 8) & 0xff) * dist / -e->fog_dist / 2 : 0;
	b = dist < e->fog_dist * 2 ? (e->ground_color & 0xff) * dist / -e->fog_dist / 2 : 0;
	return ((r << 16) + (g << 8) + b);
}
