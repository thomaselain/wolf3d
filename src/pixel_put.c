/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:41:21 by telain            #+#    #+#             */
/*   Updated: 2016/06/29 17:46:54 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;

	new_color = mlx_get_color_value(e->mlx, color);
	e->data[y * e->sl + x * e->bpp / 8] = (new_color & 0xff);
	e->data[y * e->sl + x * e->bpp / 8 + 1] = (new_color & 0xff00) >> 8;
	e->data[y * e->sl + x * e->bpp / 8 + 2] = (new_color & 0xff0000) >> 16;
}
