/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:55:49 by telain            #+#    #+#             */
/*   Updated: 2016/10/01 03:14:52 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	move(t_env *e)
{
	if ((e->map[(int)(e->pos[1] + e->move_y / 2)]
			[(int)(e->pos[0] + e->move_x / 2)] == '0') ||
		(e->map[(int)(e->pos[1] + e->move_y / 2)]
			[(int)(e->pos[0] + e->move_x / 2)] == '2' && e->xray == 1))
	{
		e->pos[0] += e->move_x * e->speed;
		e->pos[1] += e->move_y * e->speed;
	}
}

int		find_key(int key, void *e)
{
	if (key == KEY_ESC)
		destroy(0, e);
	else if (key == KEY_F || key == KEY_R)
		do_input(e, key);
	return (key);
}

int		expose_find_key(int key, void *e)
{
	if (key == KEY_LEFT ||
			key == KEY_RIGHT || key == KEY_W || key == KEY_A || key == KEY_S ||
			key == KEY_D)
		do_input(e, key);
	return (key);
}

void	do_input(t_env *e, int key)
{
	if (key == KEY_LEFT)
		e->angle -= 5;
	else if (key == KEY_RIGHT)
		e->angle += 5;
	if (key == KEY_F)
		e->fog_dist = (e->fog_dist == 4) ? 15 : 4;
	if (key == KEY_R)
		e->xray = (e->xray == 0) ? 1 : 0;
	move_inputs(e, key);
	refresh(0, e);
}

void	move_inputs(t_env *e, int key)
{
	if (key == KEY_A)
	{
		e->move_x = -cos(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90)) / 2;
		e->move_y = -sin(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90)) / 2;
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
		e->move_x = cos(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90)) / 2;
		e->move_y = sin(DEG_TO_RAD(e->angle) + DEG_TO_RAD(90)) / 2;
	}
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(e);
}
