/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 15:58:15 by telain            #+#    #+#             */
/*   Updated: 2016/08/23 17:08:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		print_map(t_env *e, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	ft_putstr("\e[1;1H\e[2J");
	while (e->map[++j])
	{
		i = -1;
		while (e->map[j][++i])
		{
			if ((int)e->pos[0] == i && (int)e->pos[1]  == j)
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
	print_infos();
	printf("x : %f\ny : %f\n", e->pos[0], e->pos[1]);
}

void		print_infos(void)
{
	ft_putstr("\n\n\t\t\e[32m|-------------------------------|\e[0m\n");
	ft_putstr("\t\t\e[32m|         \e[0mTouches :             \e[32m|\e[0m\n");
	ft_putstr("\t\t\e[32m|   \e[0mw/a/s/d    : Deplacement    \e[32m|\e[0m\n");
	ft_putstr("\t\t\e[32m|   \e[0mArrow keys : Camera         \e[32m|\e[0m\n");
	ft_putstr("\t\t\e[32m|   \e[0mF          : Flashlight     \e[32m|\e[0m\n");
	ft_putstr("\t\t\e[32m|   \e[0mR          : Xray           \e[32m|\e[0m\n");
	ft_putstr("\t\t\e[32m|   \e[0mEsc        : Close Wolf3d   \e[32m|\e[0m\n");
	ft_putstr("\t\t\e[32m|-------------------------------|\e[0m\n");
}
