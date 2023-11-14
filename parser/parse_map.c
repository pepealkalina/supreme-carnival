/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:49:07 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/14 15:55:02 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int check_last (char *line)
{
	int i;

	i = 0;
	if (!line)
		return (FALSE);
	while (line[i])
	{
		if (line[i] != WALL || line[i] != ' ')
			return (FALSE);
		i++;
	}
	return(true);
}

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
	if (!map)
		return (FALSE);
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
					|| map[irow][icol + 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int	ft_is_tile(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!((map[i][j] == WALL || map[i][j] == VOID)
				|| (map[i][j] == START_N || map[i][j] == START_S)
				|| (map[i][j] == START_E || map[i][j] == START_W)
				|| map[i][j] == ' '))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
int	ft_is_valid(t_map *map)
{
	if (!ft_is_tile(map->map_content))
		return (FALSE);
	if (!ft_get_start_pos(&map->start, map->map_content))
		return (FALSE);
	if (!is_map_closed(&map->start, (const char **)map->map_content))
		return (FALSE);
	return (TRUE);
}


static void ft_reverse_map(t_cub3d *cub3d)
{
	char **tmp;
	int	i;

	tmp = NULL;
	i = ft_pplen(cub3d->file_parser.map.map_content) - 1;
	while(i >= 0)
	{
		tmp = ft_add_pp(ft_strndup2(cub3d->file_parser.map.map_content[i], ft_strlen(cub3d->file_parser.map.map_content[i]) - 1), tmp);
		i--;
	}
	ft_freevpp((void **)cub3d->file_parser.map.map_content);
	cub3d->file_parser.map.map_content = tmp;
}

int	ft_parse_map(t_cub3d *cub3d)
{
	ft_get_map(cub3d);
	if (!cub3d->file_parser.map.map_content)
		return (FALSE);
	ft_reverse_map(cub3d);
	ft_printpp(cub3d->file_parser.map.map_content);
	if (!ft_is_valid(&cub3d->file_parser.map))
		return (FALSE);
	return (TRUE);
}
