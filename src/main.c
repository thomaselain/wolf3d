/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:17:33 by telain            #+#    #+#             */
/*   Updated: 2016/08/23 18:05:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_putendl("Usage : ./wolf3d <map>");
		exit(0);
	}
	new_env(&e, av[1]);
	mlx_key_hook(e.win, find_key, &e);
	mlx_hook(e.win, 17, 0, destroy, &e);
	mlx_hook(e.win, 2, (1L<<0), expose_find_key, &e);
	draw_window(&e);
	mlx_loop(e.mlx);
	return (0);
}

int		destroy(int key, void *e)
{
	if (key || e)
		;
	exit(0);
	return (0);
}
