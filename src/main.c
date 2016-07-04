/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:17:33 by telain            #+#    #+#             */
/*   Updated: 2016/07/04 16:43:43 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac)
		ft_putendl(av[0]);
	new_env(&e);
	mlx_key_hook(e.win, find_key, &e);
	mlx_hook(e.win, 2, 0, expose_find_key, &e);
	draw_window(&e);
	mlx_loop(e.mlx);
	return (0);
}
