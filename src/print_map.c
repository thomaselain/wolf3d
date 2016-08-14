/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:58:15 by telain            #+#    #+#             */
/*   Updated: 2016/08/14 14:55:15 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		print_map(t_env *e, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (e->map[++j])
	{
		i = -1;
		while (e->map[j][++i])
		{
			if (e->pos[0] / 64 == i && e->pos[1] / 64 == j)
				ft_putstr("\e[31m");
			else if (x == i && y == j)
				ft_putstr("\e[32m");
			else
				ft_putstr("\e[0m");
			ft_putchar(e->map[j][i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
