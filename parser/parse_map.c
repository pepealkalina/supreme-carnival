/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:49:07 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/13 15:15:23 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_get_map(t_cub3d *cub3d)
{
	int		i;

	cub3d->file_parser.map.map_content = NULL;
	cub3d->file_parser.file_lines = ft_pplen(cub3d->file_content);
	i = cub3d->file_parser.file_lines - 1;
	while (cub3d->file_content[i] \
	[ft_strlen(cub3d->file_content[i]) - 2] == WALL)
	{
		cub3d->file_parser.map.map_content = \
		ft_add_pp(cub3d->file_content[i], cub3d->file_parser.map.map_content);
		i--;
	}
	return (TRUE);
}

int	ft_get_start_pos(t_player *start, char **map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		ft_sub_get_start_pos(start, map[i], &flag, i);
		i++;
	}
	if (flag != 1)
		return (FALSE);
	return (TRUE);
}

int	is_in_border(char **map, int row, int col)
{
	if (row == 0 || col == 0
		|| row == ft_pplen(map) - 1 || col == ft_strlen(map[row]) - 1)
		return (FALSE);
	return (TRUE);
}

int	is_map_closed(t_player *start, const char **map)
{
	int	irow;
	int	icol;

	if (!is_in_border((char **)map, start->pos_x, start->pos_y))
		return (0);
	irow = -1;
	while (++irow < ft_pplen((char **)map) - 1)
	{
		icol = -1;
		while (++icol < ft_strlen(map[irow]))
		{
			if (map[irow][icol] == VOID)
			{
				if (!is_in_border((char **)map, irow, icol) \
					|| map[irow - 1][icol] == ' ' \
					|| map[irow][icol - 1] == ' ' \
					|| map[irow + 1][icol] == ' ' \
					|| map[irow][icol + 1] == ' '
					|| map[irow][icol + 1] == '\n'\
					|| map[irow][icol - 1] == '\n')
					return (0);
			}
		}
	}
	return (1);
}

int	ft_is_valid(t_map *map)
{
	if (!ft_get_start_pos(&map->start, map->map_content))
		return (FALSE);
	if (!is_map_closed(&map->start, (const char **)map->map_content))
		return (FALSE);
	return (TRUE);
}

void swap(char **a, char **b)
{
	printf("a %s",*a);
	printf("b %s",*b);
	char *temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_reverse_map(t_map *map)
{
	int	init;
	int	end;

	init = 0;
	end = ft_pplen(map->map_content);
	while (init < end)
	{
		swap(&map->map_content[init], &map->map_content[end]);
		init++;
		end--;
	}
}

int	ft_parse_map(t_cub3d *cub3d)
{
	ft_get_map(cub3d);
	ft_reverse_map(&cub3d->file_parser.map);
	ft_printpp(cub3d->file_parser.map.map_content);	
	if (!ft_is_valid(&cub3d->file_parser.map))
		return (FALSE);
	return (TRUE);
}
