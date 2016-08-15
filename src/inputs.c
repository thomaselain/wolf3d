/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:55:49 by telain            #+#    #+#             */
/*   Updated: 2016/08/15 21:09:43 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move(t_env *e)
{
	if (e->map[(int)(e->pos[1] + e->move_y)]
			[(int)(e->pos[0] + e->move_x)] != '1')
	{
		e->pos[0] += e->move_x * e->speed;
		e->pos[1] += e->move_y * e->speed;
	}
}

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
	if (key == KEY_LEFT)
		e->angle -= 2;
	else if (key == KEY_RIGHT)
		e->angle += 2;
	if (key == KEY_A)
	{
		e->move_x = -cos(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90));
		e->move_y = -sin(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90));
	}
	else if (key == KEY_W)
	{
		e->move_x = cos(DEG_TO_RAD(e->angle));
		e->move_y = sin(DEG_TO_RAD(e->angle));
	}
	else if (key == KEY_S)
	{
		e->move_x = -cos(DEG_TO_RAD(e->angle));
		e->move_y = -sin(DEG_TO_RAD(e->angle));
	}
	else if (key == KEY_D)
	{
		e->move_x = cos(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90));
		e->move_y = sin(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90));
	}
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(e);
	refresh(0, e);
}
