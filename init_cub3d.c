/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:21:04 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 15:31:27 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

static t_rgb	*ft_init_rgb_parser(void)
{
	t_rgb	*tmp;

	tmp = (t_rgb *)malloc(sizeof(t_rgb));
	if (!tmp)
		return (NULL);
	tmp->blue = 0;
	tmp->red = 0;
	tmp->green = 0;
}

static t_texture	*ft_init_texture_parser(void)
{
	t_texture	*tmp;

	tmp = (t_texture *)malloc(sizeof(t_texture));
	if (!tmp)
		return (NULL);
	tmp->direction = NULL;
	tmp->file = NULL;
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
	tmp->file_lines = 0;
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
