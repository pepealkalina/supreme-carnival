/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_len_line_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:44 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:12:00 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_len_ray(t_cub3d *cub3d)
{
	if (cub3d->raycaster.side == 0 || cub3d->raycaster.side == 1)
		cub3d->raycaster.ray_len = (cub3d->raycaster.side_x
				- cub3d->raycaster.delta_x);
	else
		cub3d->raycaster.ray_len = (cub3d->raycaster.side_y
				- cub3d->raycaster.delta_y);
}

void	ft_line_height(t_cub3d *cub3d)
{
	cub3d->raycaster.line_height = (int)(HEIGHT / cub3d->raycaster.ray_len);
}

void	ft_line_start(t_cub3d *cub3d)
{
	cub3d->raycaster.line_start = -cub3d->raycaster.line_height
		/ 2 + HEIGHT / 2;
	if (cub3d->raycaster.line_start < 0)
		cub3d->raycaster.line_start = 0;
}

void	ft_line_end(t_cub3d *cub3d)
{
	cub3d->raycaster.line_end = cub3d->raycaster.line_height
		/ 2 + HEIGHT / 2;
	if (cub3d->raycaster.line_end >= HEIGHT)
		cub3d->raycaster.line_end = HEIGHT - 1;
}
