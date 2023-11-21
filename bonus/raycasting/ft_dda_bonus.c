/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:10:49 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:11:15 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_dda(t_cub3d *cub3d)
{
	cub3d->raycaster.hit = 0;
	while (cub3d->raycaster.hit == 0)
	{
		if (cub3d->raycaster.side_x < cub3d->raycaster.side_y)
		{
			cub3d->raycaster.side_x += cub3d->raycaster.delta_x;
			cub3d->raycaster.map_x += cub3d->raycaster.step_x;
			if (cub3d->raycaster.ray_dir_x < 0)
				cub3d->raycaster.side = 0;
			else
				cub3d->raycaster.side = 1;
		}
		else
		{
			cub3d->raycaster.side_y += cub3d->raycaster.delta_y;
			cub3d->raycaster.map_y += cub3d->raycaster.step_y;
			if (cub3d->raycaster.ray_dir_y < 0)
				cub3d->raycaster.side = 2;
			else
				cub3d->raycaster.side = 3;
		}
		if (cub3d->raycaster.map
			[cub3d->raycaster.map_y][cub3d->raycaster.map_x] == '1')
			cub3d->raycaster.hit = 1;
	}
}
