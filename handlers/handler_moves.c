/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:15:35 by paescano          #+#    #+#             */
/*   Updated: 2023/11/13 16:41:43 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_move_forward(t_cub3d *cub3d)
{
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y
			+ cub3d->raycaster.dir_y * MOVE_SPEED)]
			[(int)(cub3d->raycaster.player_x)] != '1')
		cub3d->raycaster.player_y = cub3d->raycaster.player_y
			+ cub3d->raycaster.dir_y * MOVE_SPEED;
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y)]
			[(int)(cub3d->raycaster.player_x
			+ cub3d->raycaster.dir_x * MOVE_SPEED)] != '1')
		cub3d->raycaster.player_x = cub3d->raycaster.player_x
			+ cub3d->raycaster.dir_x * MOVE_SPEED;
	ft_reload_background(cub3d);
	ft_raycasting(cub3d);
}

void	ft_move_backward(t_cub3d *cub3d)
{
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y
			- cub3d->raycaster.dir_y * MOVE_SPEED)]
			[(int)(cub3d->raycaster.player_x)] != '1')
		cub3d->raycaster.player_y = cub3d->raycaster.player_y
			- cub3d->raycaster.dir_y * MOVE_SPEED;
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y)]
			[(int)(cub3d->raycaster.player_x
			- cub3d->raycaster.dir_x * MOVE_SPEED)] != '1')
		cub3d->raycaster.player_x = cub3d->raycaster.player_x
			- cub3d->raycaster.dir_x * MOVE_SPEED;
	ft_reload_background(cub3d);
	ft_raycasting(cub3d);
}

void	ft_move_left(t_cub3d *cub3d)
{
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y
			- cub3d->raycaster.plane_y * MOVE_SPEED)]
			[(int)(cub3d->raycaster.player_x)] != '1')
		cub3d->raycaster.player_y = cub3d->raycaster.player_y
			- cub3d->raycaster.plane_y * MOVE_SPEED;
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y)]
			[(int)(cub3d->raycaster.player_x
			- cub3d->raycaster.plane_x * MOVE_SPEED)] != '1')
		cub3d->raycaster.player_x = cub3d->raycaster.player_x
			- cub3d->raycaster.plane_x * MOVE_SPEED;
	ft_reload_background(cub3d);
	ft_raycasting(cub3d);
}

void	ft_move_right(t_cub3d *cub3d)
{
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y
			+ cub3d->raycaster.plane_y * MOVE_SPEED)]
			[(int)(cub3d->raycaster.player_x)] != '1')
		cub3d->raycaster.player_y = cub3d->raycaster.player_y
			+ cub3d->raycaster.plane_y * MOVE_SPEED;
	if (cub3d->raycaster.map[(int)(cub3d->raycaster.player_y)]
			[(int)(cub3d->raycaster.player_x
			+ cub3d->raycaster.plane_x * MOVE_SPEED)] != '1')
		cub3d->raycaster.player_x = cub3d->raycaster.player_x
			+ cub3d->raycaster.plane_x * MOVE_SPEED;
	ft_reload_background(cub3d);
	ft_raycasting(cub3d);
}
