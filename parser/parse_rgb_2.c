/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:48:39 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/02 16:27:32 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

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
	int	i;

	i = 0;
	while (colors[i])
	{
		if (!ft_checknum(ft_split(ft_split(colors[i], ' ')[1], ',')))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	ft_save_each(t_rgb *color, char **splited_colors)
{
	int32_t	a;

	a = 0xFF;
	color->red = ft_atoi(splited_colors[0]);
	color->green = ft_atoi(splited_colors[1]);
	color->blue = ft_atoi(splited_colors[2]);
	color->hexa = color->red << 24 | color->green << 16 | color->blue << 8 | a;
}

void	ft_save_rgb(t_cub3d *cub3d, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (!ft_strncmp(ft_split(textures[i], ' ')[0], "F", 2))
			ft_save_each(cub3d->file_parser->floor, \
			ft_split(ft_split(textures[i], ' ')[1], ','));
		if (!ft_strncmp(ft_split(textures[i], ' ')[0], "C", 2))
			ft_save_each(cub3d->file_parser->ceiling, \
			ft_split(ft_split(textures[i], ' ')[1], ','));
		i++;
	}
}