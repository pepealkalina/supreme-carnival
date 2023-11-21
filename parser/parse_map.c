/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:49:07 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/21 10:48:33 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	check_last(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (FALSE);
	while (line[i])
	{
		if (line[i] != WALL || line[i] != ' ')
			return (FALSE);
		i++;
	}
	return (true);
}

int	ft_get_map(t_cub3d *cub3d)
{
	int		i;

	cub3d->file_parser.map.map_content = NULL;
	cub3d->file_parser.file_lines = ft_pplen(cub3d->file_content);
	i = cub3d->file_parser.file_lines - 1;
	while (cub3d->file_content[i] \
	[ft_strlen(cub3d->file_content[i]) - 2] == WALL || cub3d->file_content[i] \
	[ft_strlen(cub3d->file_content[i]) - 2] == ' ')
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

int	ft_parse_map(t_cub3d *cub3d)
{
	ft_get_map(cub3d);
	if (!cub3d->file_parser.map.map_content)
		return (FALSE);
	ft_reverse_map(cub3d);
	ft_fill_map(cub3d);
	if (!ft_is_valid(cub3d, &cub3d->file_parser.map))
		return (FALSE);
	return (TRUE);
}
