/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_camera_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:26:37 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:26:43 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static void	ft_rotate(t_cub3d *cub3d, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->raycaster.dir_x;
	cub3d->raycaster.dir_x = cub3d->raycaster.dir_x * cos(angle)
		- cub3d->raycaster.dir_y * sin(angle);
	cub3d->raycaster.dir_y = old_dir_x * sin(angle)
		+ cub3d->raycaster.dir_y * cos(angle);
	old_plane_x = cub3d->raycaster.plane_x;
	cub3d->raycaster.plane_x = cub3d->raycaster.plane_x * cos(angle)
		- cub3d->raycaster.plane_y * sin(angle);
	cub3d->raycaster.plane_y = old_plane_x * sin(angle)
		+ cub3d->raycaster.plane_y * cos(angle);
}

void	ft_rotate_left(t_cub3d *cub3d)
{
	ft_rotate(cub3d, -ROTATION_SPEED);
	ft_reload_background(cub3d);
	ft_raycasting(cub3d);
}

void	ft_rotate_right(t_cub3d *cub3d)
{
	ft_rotate(cub3d, ROTATION_SPEED);
	ft_reload_background(cub3d);
	ft_raycasting(cub3d);
}
