/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 13:55:49 by telain            #+#    #+#             */
/*   Updated: 2016/06/30 21:40:56 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		do_input(e, key);
	return (key);
}

void	do_input(t_env *e, int key)
{
	if (e)
		;
	if (key == KEY_UP)
		ft_putstr("up\n");
	else if (key == KEY_DOWN)
		ft_putstr("down\n");
	else if (key == KEY_LEFT)
		ft_putstr("left\n");
	else if (key == KEY_RIGHT)
		ft_putstr("right\n");
}
