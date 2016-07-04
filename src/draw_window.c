/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:44:11 by telain            #+#    #+#             */
/*   Updated: 2016/07/04 16:47:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		refresh(int key, void *e)
{
	draw_window(e);
	return (key);
}

void	draw_window(t_env *e)
{
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	scan(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
