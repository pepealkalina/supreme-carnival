/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:29 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/21 16:49:18 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_sub_get_start_pos(t_player *start, \
char *map, int *flag, int line)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i++])
	{
		if (map[i] != VOID)
		{
			if (map[i] == START_N || map[i] == START_S
				|| map[i] == START_E || map[i] == START_W)
			{
				if (*flag == 0)
				{
					start->pos_x = i;
					start->pos_y = line;
					start->direction = (char)map[i];
					map[i] = VOID;
				}
				*flag += 1;
			}
		}
	}
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

int	ft_is_valid(t_cub3d *cub3d, t_map *map)
{
	if (!ft_is_tile(cub3d->raycaster.map))
		return (FALSE);
	if (!ft_get_start_pos(&map->start, cub3d->raycaster.map))
		return (FALSE);
	if (!is_map_closed(&map->start, (const char **)cub3d->raycaster.map))
		return (FALSE);
	return (TRUE);
}

void	ft_reverse_map(t_cub3d *cub3d)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	i = ft_pplen(cub3d->file_parser.map.map_content) - 1;
	while (i > 0)
	{
		tmp = ft_add_pp(ft_strndup2(cub3d->file_parser.map.map_content[i],
					ft_strlen(cub3d->file_parser.map.map_content[i]) - 1), tmp);
		i--;
	}
	tmp = ft_add_pp(ft_strndup2(cub3d->file_parser.map.map_content[0],
				ft_strlen(cub3d->file_parser.map.map_content[0])), tmp);
	ft_freevpp((void **)cub3d->file_parser.map.map_content);
	cub3d->raycaster.map = tmp;
}

int	is_map_closed(t_player *start, const char **map)
{
	int	irow;
	int	icol;

	if (!is_in_border((char **)map, start->pos_y, start->pos_x))
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
