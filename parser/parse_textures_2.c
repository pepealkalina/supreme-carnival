/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:01:51 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 18:11:17 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_save_each(t_texture *texture, char **splited_texture)
{
	texture->direction = splited_texture[0];
	texture->file = splited_texture[1];
}

void	ft_save_textures(t_cub3d *cub3d, char **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		if (!ft_strncmp(ft_split(textures[i], ' ')[0], "NO", 2))
			ft_save_each(cub3d->file_parser->north, ft_split(textures[i], ' '));
		if (!ft_strncmp(ft_split(textures[i], ' ')[0], "SO", 2))
			ft_save_each(cub3d->file_parser->south, ft_split(textures[i], ' '));
		if (!ft_strncmp(ft_split(textures[i], ' ')[0], "WE", 2))
			ft_save_each(cub3d->file_parser->west, ft_split(textures[i], ' '));
		if (!ft_strncmp(ft_split(textures[i], ' ')[0], "EA", 2))
			ft_save_each(cub3d->file_parser->east, ft_split(textures[i], ' '));
		i++;
	}
}
