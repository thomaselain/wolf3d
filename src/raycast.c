/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 22:05:46 by telain            #+#    #+#             */
/*   Updated: 2016/08/15 17:03:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_raycast(t_env *e)
{
	e->diff_x = cos(DEG_TO_RAD(e->angle));
	e->diff_y = sin(DEG_TO_RAD(e->angle));
}

void	raycast(t_env *e)
{
	e->hit = 0;
	e->ray_x = e->pos[0];
	e->ray_y = e->pos[1];
	while (e->hit == 0)
	{
		if (e->map[(int)e->ray_y][(int)e->ray_x] != '0')
			e->hit = 1;
		else
		{
			e->ray_x += e->diff_x;
			e->ray_y += e->diff_y;
		}
	}
	print_map(e, (int)e->ray_x, (int)e->ray_y);
}

void	scan(t_env *e)
{
	init_raycast(e);
	printf("e->diff_x : %f\t\te->diff_y : %f\ne->angle : %f\n\n", e->diff_x, e->diff_y, e->angle);
	raycast(e);
}
