/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:55:46 by telain            #+#    #+#             */
/*   Updated: 2016/07/04 17:39:22 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	new_env(t_env *e)
{
	load_map(e);
	e->angle = 20 * (M_PI / 180);
	e->pos[0] = 7.6547;
	e->pos[1] = 8.786;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Loup trois D");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
}

void	load_map(t_env *e)
{
	int		fd;
	int		size;
	char	*line;

	fd = open("maps/map_1", O_RDONLY, S_IREAD);
	size = 0;
	while (get_next_line(fd, &line) > 0)
		size++;
	close(fd);
	e->map_size_y = size;
	e->map = (char**)ft_memalloc(sizeof(char*) * e->map_size_y);
	e->map_size_x = ft_strlen(line);
	while (size > 0)
		e->map[size--] = (char*)ft_memalloc(sizeof(char) * e->map_size_x);
	fd = open("maps/map_1", O_RDONLY, S_IREAD);
	while (get_next_line(fd, &line) > 0)
	{
		e->map[size++] = line;
		ft_putendl(line);
	}
	close(fd);
}
