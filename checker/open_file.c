/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:36 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 11:52:54 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

static int	ft_get_map_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\n')
		width++;
	return (width);
}

static int	ft_add_line(t_game *game, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->height_map++;
	tmp = (char **)malloc(sizeof(char *) * (game->height_map + 1));
	if (!tmp)
		ft_error_free("Error\nMalloc failed\n", game->map);
	tmp[game->height_map] = NULL;
	while (i < game->height_map - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

void	ft_map_set_up(char **argv)
{
	char	*readmap;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap not found\n");
	while (1)
	{
		readmap = get_next_line(fd);
		if (!ft_add_line(game, readmap))
			break ;
	}
	close (game->fd);
	game->width_map = ft_get_map_width(game->map[0]);
}
