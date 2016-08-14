/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 16:21:32 by telain            #+#    #+#             */
/*   Updated: 2016/08/14 22:04:37 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		find_vert_inter(t_env *e)
{
	e->vy = (e->angle >= 0 && e->angle <= 180) ?
		(int)(e->pos[1] / 64) * 64 - 64 : (int)(e->pos[1] / 64) * 64 + 64;
	e->vx = e->pos[0] + (e->pos[1] - e->vy) / tan(DEG_TO_RAD(e->angle));
	e->diff_vy = (e->angle >= 0 && e->angle <= 180) ? -64 : 64;
	e->diff_vx = 64 * tan(DEG_TO_RAD(e->angle));
	printf("e->vx = %d\ne->vy = %d\n", e->vx / 64, e->vy / 64);
	while (1)
	{
		if (e->vy < 0 || e->vy > e->map_size_y * 64
				|| e->vx < 0 || e->vx > e->map_size_x * 64)
			return (1000);
		else if (e->map[e->vx / 64][e->vy / 64] != '0')
		{
			e->vert_dist = ft_sqrt(ft_power(e->vx - e->pos[0], 2) +				
					ft_power(e->vy - e->pos[1], 2));
			return (e->vert_dist);
		}
		else
		{
			e->vx += e->diff_vx;
			e->vy += e->diff_vy;
		}
	}
	return (-1);
}

int		find_hori_inter(t_env *e)
{
	e->hx = (e->angle >= 90 && e->angle <= 270) ?
		(int)(e->pos[0] / 64) * 64 - 64: (int)(e->pos[0] / 64) * 64 + 64;
	e->hy = e->pos[1] + (e->pos[0] - e->hx) / tan(DEG_TO_RAD(e->angle));
	e->diff_hx = (e->angle >= 90  && e->angle <= 270) ? -64 : 64;
	e->diff_hy = 64 / tan(DEG_TO_RAD(e->angle));
	printf("e->hx = %d\ne->hy = %d\n", e->hx / 64, e->hy / 64);
	while (1)
	{
		if (e->hy < 0 || e->hy > e->map_size_y * 64
				|| e->hx < 0 || e->hx > e->map_size_x * 64)
			return (1000);
		else if (e->map[e->hx / 64][e->hy / 64] != '0')
		{
			e->hori_dist = ft_sqrt(ft_power(e->hx - e->pos[0], 2) +
					ft_power(e->hy - e->pos[1], 2));
			return (e->hori_dist);
		}
		else
		{
			e->hx += e->diff_hx;
			e->hy += e->diff_hy;
		}
	}
	return (-1);
}

void	raycast(t_env *e)
{
	if (e)
		;
}

void	scan(t_env *e)
{
	if (find_vert_inter(e) > find_hori_inter(e))
	{
		print_map(e, e->hx / 64, e->hy / 64);
	}
	else
	{
		print_map(e, e->vx / 64, e->vy / 64);
	}
	ft_putendl("Hori");
	ft_putnendl(e->hori_dist);
	ft_putendl("Vert");
	ft_putnendl(e->vert_dist);
	ft_putnendl(e->angle);
}
