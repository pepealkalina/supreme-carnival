/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:48:39 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/15 12:42:27 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	ft_checknum(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]) && rgb[i][j] != '\n')
				return (FALSE);
			j++;
		}
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_is_rgb(const char **colors)
{
	int		i;
	char	**split;
	char	**split_splited;

	i = 0;
	while (colors[i])
	{
		split_splited = ft_split(colors[i], ' ');
		split = ft_split(split_splited[1], ',');
		if (!ft_checknum(split))
		{
			ft_freevpp((void **)split);
			ft_freevpp((void **)split_splited);
			return (FALSE);
		}
		i++;
		ft_freevpp((void **)split);
		ft_freevpp((void **)split_splited);
	}
	return (TRUE);
}

int	ft_rgba_to_hex(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	ft_save_each(t_rgb *color, char **splited_colors)
{
	int	a;

	a = 0xFF;
	color->hexa = ft_rgba_to_hex(ft_atoi(splited_colors[0]),
			ft_atoi(splited_colors[1]), ft_atoi(splited_colors[2]), a);
	ft_freevpp((void **)splited_colors);
}

void	ft_save_rgb(t_cub3d *cub3d, char **textures)
{
	int		i;
	char	**split;

	i = 0;
	while (textures[i])
	{
		split = ft_split(textures[i], ' ');
		if (!ft_strncmp(split[0], "F", 2))
			ft_save_each(&cub3d->file_parser.floor, \
			ft_split(split[1], ','));
		if (!ft_strncmp(split[0], "C", 2))
			ft_save_each(&cub3d->file_parser.ceiling, \
			ft_split(split[1], ','));
		ft_freevpp((void **)split);
		i++;
	}
}
