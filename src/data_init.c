/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:55:46 by telain            #+#    #+#             */
/*   Updated: 2016/08/16 17:23:12 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	new_env(t_env *e, char *av)
{
	e->map_name = av;
	load_map(e);
	e->speed = 0.25;
	e->angle = 0;
	e->pos[0] = 2;
	e->pos[1] = 2;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, ft_strjoin("Loup3d : ", av));
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
}

void	load_map(t_env *e)
{
	int		fd;
	int		size;
	char	*line;

	fd = open(e->map_name, O_RDONLY, S_IREAD);
	size = 0;
	while (get_next_line(fd, &line) > 0)
		size++;
	close(fd);
	e->map_size_y = size;
	size = 0;
	e->map = (char**)ft_memalloc(sizeof(char*) * e->map_size_y + 1);
	fd = open(e->map_name, O_RDONLY, S_IREAD);
	while (get_next_line(fd, &line) > 0)
	{
		e->map_size_x = ft_strlen(line) / 2 + 1;
		e->map[size++] = load_line(line, e->map_size_x);
	}
	close(fd);
}

char	*load_line(char *line, int size)
{
	int		i;
	int		j;
	char	*new;

	new = ft_strnew(size);
	i = -1;
	j = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) == 1)
			new[++j] = line[i];
	}
	return (new);
}
