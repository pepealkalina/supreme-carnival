/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:49:07 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/04 16:25:06 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_get_map(t_cub3d *cub3d)
{
	int	i;

	cub3d->file_parser->file_lines = ft_pplen(cub3d->file_content);
	i = cub3d->file_parser->file_lines - 1;
	while (cub3d->file_content[i] \
	[ft_strlen(cub3d->file_content[i]) - 2] == WALL)
	{
		if (ft_split(cub3d->file_content[i], ' ')[0][0] != WALL)
		{
			if (cub3d->file_parser->map->map_content != NULL)
				ft_freevpp((void **)cub3d->file_parser->map->map_content);
			return (FALSE);
		}
		cub3d->file_parser->map->map_content = \
		ft_add_pp(cub3d->file_content[i], cub3d->file_parser->map->map_content);
		i--;
	}
	return (TRUE);
}

int	ft_flood_fill(char **map, int x, int y)
{
	if (!(x < 1 || y < 1 || y >= ft_strlen(map[y]) || x >= ft_pplen(map)
			|| map[y][x] == WALL || map[y][x] == 'B'))
	{
		if ((map[y + 1] != NULL && map[y + 1][x] == ' ')
			|| (map[y - 1] != NULL && map[y - 1][x] == ' ')
			|| ((map[y][x + 1] != '\n' || map[y][x + 1] != '\0')
				&& map[y][x + 1] == ' ')
			|| (map[y][x - 1] == ' '))
		{
			printf("a %d\n", x);
			return (FALSE);
		}
		map[y][x] = 'B';
		ft_flood_fill(map, x, y + 1);
		ft_flood_fill(map, x + 1, y);
		ft_flood_fill(map, x, y - 1);
		ft_flood_fill(map, x - 1, y);
	}
	return (TRUE);
}

int	ft_is_valid(t_map *map)
{
	char	**tmp_map;

	tmp_map = ft_ppdup(map->map_content);
	//if (!ft_get_start_pos(map->start, (const char **)map->map_content))
	//	return (FALSE); aqui la funcion no existe
	if (!ft_flood_fill(tmp_map, map->start->pos_x, map->start->pos_y))
		return (FALSE);
	ft_freevpp((void **)tmp_map);
	return (TRUE);
}

int	ft_parse_map(t_cub3d *cub3d)
{
	ft_get_map(cub3d); // el segfault esta aqui
	if (!ft_is_valid(cub3d->file_parser->map))
		return (FALSE);
	ft_printpp(cub3d->file_parser->map->map_content);
	return (TRUE);
}
