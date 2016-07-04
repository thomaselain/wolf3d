/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 20:21:06 by telain            #+#    #+#             */
/*   Updated: 2016/07/04 17:40:54 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		find_first_inter(t_env *e)
{
	double	x;
	double	y;
	double	a;
	double	b;

	x = e->pos[0];
	a = tan(e->angle);
	b = e->pos[1];
	y = a * x + b;
	while (e->map[(int)x][(int)y] == 32)
	{
		pixel_put(e, (int)x, (int)y, 0xffffff);
		y = a * x++ + b;
	}
	ft_putendl("\n\nMur detecte ! \nCoordonnees :");
	printf("x = %d\ny = %d\na = %f\n\n", (int)x, (int)y, a);
	return (1);
}

void	scan(t_env *e)
{
	double	xa;
//	double	ya;
	double	pos_x;
	double	pos_y;
	int		line;

	line = -1;
	pos_x = e->pos[0];
	pos_y = e->pos[1];
	xa = find_first_inter(e);
	while (++line < WIN_X)
	{
//		raycast(e, line);
	}
}
