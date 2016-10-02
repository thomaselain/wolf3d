/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:26:00 by telain            #+#    #+#             */
/*   Updated: 2016/10/01 14:37:12 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	display_error(int error, t_env *e)
{
	if (error == 0)
		ft_putendl("A malloc has failed");
	else if (error == 1)
		ft_putendl("Something went wrong");
	else if (error == 2)
		ft_putendl("The Skybox was not found");
	else if (error == 3)
		ft_putendl("Not a valid map (You may have spawned in a wall, though)");
	else if (error == 4)
	{
		ft_putstr("\n\t\t--Help--\n\nw/a/s/d\t\t\t: move\narrow left/right\t:");
		ft_putendl(" look around \nr\t\t\t: super xray\nesc\t\t\t: leave");
		ft_putendl("f\t\t\t: flashlight\n");
	}
	destroy(0, e);
}
