/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:21:04 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/07 11:32:32 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static t_rgb	*ft_init_rgb_parser(void)
{
	t_rgb	*tmp;

	tmp = (t_rgb *)malloc(sizeof(t_rgb));
	if (!tmp)
		return (NULL);
	tmp->hexa = 0;
	return (tmp);
}

static t_map	*ft_init_map_parser(void)
{
	t_map	*tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	if (!tmp)
		return (NULL);
	tmp->max_heigth = 0;
	tmp->max_with = 0;
	tmp->map_content = NULL;
	tmp->start = (t_player *)malloc(sizeof(t_player));
	if (!tmp)
		return (NULL);
	tmp->start->pos_x = 0;
	tmp->start->pos_y = 0;
	return (tmp);
}

static t_texture	*ft_init_texture_parser(void)
{
	t_texture	*tmp;

	tmp = (t_texture *)malloc(sizeof(t_texture));
	if (!tmp)
		return (NULL);
	tmp->direction = NULL;
	tmp->file = NULL;
	tmp->tex_xpm = NULL;
	tmp->tex_int = NULL;
	return (tmp);
}

static t_file	*ft_init_file_parse(void)
{
	t_file	*tmp;

	tmp = (t_file *)malloc(sizeof(t_file));
	if (!tmp)
		return (NULL);
	tmp->north = ft_init_texture_parser();
	tmp->south = ft_init_texture_parser();
	tmp->east = ft_init_texture_parser();
	tmp->west = ft_init_texture_parser();
	tmp->ceiling = ft_init_rgb_parser();
	tmp->floor = ft_init_rgb_parser();
	tmp->map = ft_init_map_parser();
	tmp->file_lines = 0;
	return (tmp);
}

t_cub3d	*ft_init_cub3d(void)
{
	t_cub3d	*tmp;

	tmp = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!tmp)
		return (NULL);
	tmp->file_content = NULL;
	tmp->file_parser = ft_init_file_parse();
	return (tmp);
}
