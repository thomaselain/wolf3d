/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 12:26:00 by telain            #+#    #+#             */
/*   Updated: 2016/06/29 17:46:43 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	display_error(int error)
{
	if (error == 0)
		ft_putendl("A malloc has failed");
	else if (error == 1)
		ft_putendl("Something went wrong");
	exit(0);
}
