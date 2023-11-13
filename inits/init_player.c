/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:30:18 by paescano          #+#    #+#             */
/*   Updated: 2023/11/13 15:12:48 by paescano         ###   ########.fr       */
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

/*para este punto hay que tener el mapa con la dirección del jugador 
sustituida por un 0, sustituir luego los valores por los buenos*/
void	ft_init_player(t_cub3d *cub3d)
{
	char	c;

	c = 'W';
	cub3d->raycaster.player_x = 26 + 0.5;
	cub3d->raycaster.player_y = 3 + 0.5;
	if (c == 'N')
		ft_set_orientation_north(cub3d);
	else if (c == 'S')
		ft_set_orientation_south(cub3d);
	else if (c == 'E')
		ft_set_orientation_east(cub3d);
	else if (c == 'W')
		ft_set_orientation_west(cub3d);
}
