/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:55:49 by telain            #+#    #+#             */
/*   Updated: 2016/08/14 14:53:46 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		find_key(int key, void *e)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_A)
		do_input(e, key);
	return (key);
}

int		expose_find_key(int key, void *e)
{
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
			key == KEY_RIGHT || key == KEY_W || key == KEY_A || key == KEY_S ||
			key == KEY_D)
		do_input(e, key);
	return (key);
}

void	do_input(t_env *e, int key)
{
	if (key == KEY_UP)
		ft_putstr("up\n");
	else if (key == KEY_DOWN)
		ft_putstr("down\n");
	else if (key == KEY_LEFT)
	{
		e->angle -= 1;
		e->angle = (e->angle < 0) ? 360 : e->angle;
	}
	else if (key == KEY_RIGHT)
	{
		e->angle += 1;
		e->angle = (e->angle > 360) ? 0 : e->angle;
	}
	else if (key == KEY_A && e->map[e->pos[1] / 64][e->pos[0] / 64 - 1] != '1')
		e->pos[0] -= 10;
	else if (key == KEY_W && e->map[e->pos[1] / 64 - 1][e->pos[0] / 64] != '1')
		e->pos[1] -= 10;
	else if (key == KEY_S && e->map[e->pos[1] / 64 + 1][e->pos[0] / 64] != '1')
		e->pos[1] += 10;
	else if (key == KEY_D && e->map[e->pos[1] / 64][e->pos[0] / 64 + 1] != '1')
		e->pos[0] += 10;
	refresh(0, e);
}
