/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:22:13 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:22:27 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_save_each(t_texture *texture, char **splited_texture)
{
	texture->direction = ft_strndup2(splited_texture[0],
			ft_strlen(splited_texture[0]));
	texture->file = ft_strndup2(splited_texture[1],
			ft_strlen(splited_texture[1]) - 1);
}

void	ft_save_textures(t_cub3d *cub3d, char **textures)
{
	int		i;
	char	**split;

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
		ft_freevpp((void **)split);
	}
}
