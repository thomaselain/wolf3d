/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:17:33 by telain            #+#    #+#             */
/*   Updated: 2016/10/01 03:26:51 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 && ft_strcmp(av[1], "help") == 0)
		display_error(4, &e);
	else if (ac != 1)
	{
		ft_putendl("Usage : ./wolf3d <help>");
		exit(0);
	}
	new_env(&e, av[0]);
	mlx_key_hook(e.win, find_key, &e);
	mlx_hook(e.win, 17, 0, destroy, &e);
	mlx_hook(e.win, 2, (1L << 0), expose_find_key, &e);
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
