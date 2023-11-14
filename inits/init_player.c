/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:30:18 by paescano          #+#    #+#             */
/*   Updated: 2023/11/14 17:21:01 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	ft_set_orientation_north(t_cub3d *cub3d)
{
	cub3d->raycaster.dir_x = 0;
	cub3d->raycaster.dir_y = -1;
	cub3d->raycaster.plane_x = 0.66;
	cub3d->raycaster.plane_y = 0;
}

static void	ft_set_orientation_south(t_cub3d *cub3d)
{
	cub3d->raycaster.dir_x = 0;
	cub3d->raycaster.dir_y = 1;
	cub3d->raycaster.plane_x = -0.66;
	cub3d->raycaster.plane_y = 0;
}

static void	ft_set_orientation_east(t_cub3d *cub3d)
{
	cub3d->raycaster.dir_x = 1;
	cub3d->raycaster.dir_y = 0;
	cub3d->raycaster.plane_x = 0;
	cub3d->raycaster.plane_y = 0.66;
}

static void	ft_set_orientation_west(t_cub3d *cub3d)
{
	cub3d->raycaster.dir_x = -1;
	cub3d->raycaster.dir_y = 0;
	cub3d->raycaster.plane_x = 0;
	cub3d->raycaster.plane_y = -0.66;
}

void	ft_init_player(t_cub3d *cub3d)
{
	cub3d->raycaster.player_x = cub3d->file_parser.map.start.pos_x + 0.5;
	cub3d->raycaster.player_y = cub3d->file_parser.map.start.pos_y + 0.5;
	if (cub3d->file_parser.map.start.direction == 'N')
		ft_set_orientation_north(cub3d);
	else if (cub3d->file_parser.map.start.direction == 'S')
		ft_set_orientation_south(cub3d);
	else if (cub3d->file_parser.map.start.direction == 'E')
		ft_set_orientation_east(cub3d);
	else if (cub3d->file_parser.map.start.direction == 'W')
		ft_set_orientation_west(cub3d);
}
