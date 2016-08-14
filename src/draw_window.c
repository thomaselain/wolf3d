/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:44:11 by telain            #+#    #+#             */
/*   Updated: 2016/07/12 20:16:26 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	clear(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	while (++j < WIN_Y)
	{
		i = -1;
		while (++i < WIN_X)
			pixel_put(e, i, j, 0x000000);
	}
	mlx_clear_window(e->mlx, e->win);
}

int		refresh(int key, void *e)
{
	clear(e);
	draw_window(e);
	return (key);
}

void	draw_window(t_env *e)
{
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	scan(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
