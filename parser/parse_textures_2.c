/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:01:51 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/07 14:43:04 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_save_each(t_texture *texture, char **splited_texture)
{
	texture->direction = splited_texture[0];
	texture->file = splited_texture[1];
	ft_freevpp((void **)splited_texture);
}

void	ft_save_textures(t_cub3d *cub3d, char **textures)
{
	int	i;
	char **split;

	i = 0;
	while (textures[i])
	{
		split = ft_split(textures[i], ' ');
		if (!ft_strncmp(split[0], "NO", 2))
			ft_save_each(&cub3d->file_parser.north, split);
		if (!ft_strncmp(split[0], "SO", 2))
			ft_save_each(&cub3d->file_parser.south, split);
		if (!ft_strncmp(split[0], "WE", 2))
			ft_save_each(&cub3d->file_parser.west, split);
		if (!ft_strncmp(split[0], "EA", 2))
			ft_save_each(&cub3d->file_parser.east, split);
		i++;
	}
}
