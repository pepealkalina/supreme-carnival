/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line_tex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:10:12 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 17:44:02 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static double	ft_calculate_wall_impact(t_cub3d *cub3d, double wall_x)
{
	if (cub3d->raycaster.side == 0 || cub3d->raycaster.side == 1)
		wall_x = cub3d->raycaster.player_y + cub3d->raycaster.ray_len
			* cub3d->raycaster.ray_dir_y;
	else
		wall_x = cub3d->raycaster.player_x + cub3d->raycaster.ray_len
			* cub3d->raycaster.ray_dir_x;
	return (wall_x - (int)(wall_x));
}

static void	ft_calculate_tex_x(t_cub3d *cub3d, xpm_t *texture)
{
	if ((cub3d->raycaster.side == 0 || cub3d->raycaster.side == 1)
		&& cub3d->raycaster.ray_dir_x > 0)
		cub3d->raycaster.tex_x = texture->texture.width
			- cub3d->raycaster.tex_x - 1;
	if ((cub3d->raycaster.side == 2 || cub3d->raycaster.side == 3)
		&& cub3d->raycaster.ray_dir_y < 0)
		cub3d->raycaster.tex_x = texture->texture.width
			- cub3d->raycaster.tex_x - 1;
}

void	ft_tex_impact(t_cub3d *cub3d, xpm_t *texture)
{
	double	wall_x;

	wall_x = ft_calculate_wall_impact(cub3d, 0.0);
	cub3d->raycaster.tex_x = (int)(wall_x * (double)(texture->texture.width));
	ft_calculate_tex_x(cub3d, texture);
}
