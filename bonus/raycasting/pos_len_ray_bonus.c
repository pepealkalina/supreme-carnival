/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_len_ray_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:12:32 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:12:40 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_pos_ray(t_cub3d *cub3d)
{
	cub3d->raycaster.ray_dir_x = cub3d->raycaster.dir_x
		+ cub3d->raycaster.plane_x * cub3d->raycaster.camera_x;
	cub3d->raycaster.ray_dir_y = cub3d->raycaster.dir_y
		+ cub3d->raycaster.plane_y * cub3d->raycaster.camera_x;
	cub3d->raycaster.map_x = (int) cub3d->raycaster.player_x;
	cub3d->raycaster.map_y = (int) cub3d->raycaster.player_y;
}

void	ft_delta_ray(t_cub3d *cub3d)
{
	if (cub3d->raycaster.ray_dir_x == 0)
		cub3d->raycaster.delta_x = 1e30;
	else
		cub3d->raycaster.delta_x = fabs(1 / cub3d->raycaster.ray_dir_x);
	if (cub3d->raycaster.ray_dir_y == 0)
		cub3d->raycaster.delta_y = 1e30;
	else
		cub3d->raycaster.delta_y = fabs(1 / cub3d->raycaster.ray_dir_y);
}

void	ft_side_ray(t_cub3d *cub3d)
{
	if (cub3d->raycaster.ray_dir_x < 0)
	{
		cub3d->raycaster.step_x = -1;
		cub3d->raycaster.side_x = (cub3d->raycaster.player_x
				- cub3d->raycaster.map_x) * cub3d->raycaster.delta_x;
	}
	else
	{
		cub3d->raycaster.step_x = 1;
		cub3d->raycaster.side_x = (cub3d->raycaster.map_x + 1.0
				- cub3d->raycaster.player_x) * cub3d->raycaster.delta_x;
	}
	if (cub3d->raycaster.ray_dir_y < 0)
	{
		cub3d->raycaster.step_y = -1;
		cub3d->raycaster.side_y = (cub3d->raycaster.player_y
				- cub3d->raycaster.map_y) * cub3d->raycaster.delta_y;
	}
	else
	{
		cub3d->raycaster.step_y = 1;
		cub3d->raycaster.side_y = (cub3d->raycaster.map_y + 1.0
				- cub3d->raycaster.player_y) * cub3d->raycaster.delta_y;
	}
}
