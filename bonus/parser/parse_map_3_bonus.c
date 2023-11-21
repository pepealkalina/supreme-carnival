/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:16:30 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:16:47 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static int	ft_get_width(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

static char	*ft_add_char(char c, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!str)
	{
		tmp = malloc(sizeof(char) * 2);
		tmp[0] = c;
		tmp[1] = '\0';
		return (tmp);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}

static char	*ft_fill_line(t_cub3d *cub3d, int line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < cub3d->file_parser.map.max_with)
	{
		if (i < ft_strlen(cub3d->raycaster.map[line]))
			tmp = ft_add_char(cub3d->raycaster.map[line][i], tmp);
		else
			tmp = ft_add_char(' ', tmp);
		i++;
	}
	return (tmp);
}

void	ft_fill_map(t_cub3d *cub3d)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	i = 0;
	cub3d->file_parser.map.max_with = ft_get_width(cub3d->raycaster.map);
	cub3d->file_parser.map.max_heigth = ft_pplen(cub3d->raycaster.map);
	while (i < cub3d->file_parser.map.max_heigth)
	{
		tmp = ft_add_pp(ft_fill_line(cub3d, i), tmp);
		i++;
	}
	ft_freevpp((void **)cub3d->raycaster.map);
	cub3d->raycaster.map = tmp;
}
