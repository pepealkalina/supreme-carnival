/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:23:31 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:24:25 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static void	ft_draw_rectangle(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = cub3d->minimap.top_left_x;
	j = cub3d->minimap.top_left_y;
	while (i < cub3d->minimap.bottom_right_x)
	{
		while (j < cub3d->minimap.bottom_right_y)
		{
			mlx_put_pixel(cub3d->img, i, j, cub3d->minimap.color);
			j++;
		}
		j = cub3d->minimap.top_left_y;
		i++;
	}
}

void	ft_draw_minimap(t_cub3d *cub3d)
{
	int			i;
	int			j;

	i = 0;
	while (cub3d->raycaster.map[i])
	{
		j = 0;
		while (cub3d->raycaster.map[i][j])
		{
			cub3d->minimap.color = BLACK;
			if (i == (int)cub3d->raycaster.player_y
				&& j == (int)cub3d->raycaster.player_x)
				cub3d->minimap.color = RED;
			else if (cub3d->raycaster.map[i][j] == '0')
				cub3d->minimap.color = WHITE;
			cub3d->minimap.top_left_x = j * 5 + 5;
			cub3d->minimap.top_left_y = i * 5 + 5;
			cub3d->minimap.bottom_right_x = cub3d->minimap.top_left_x + 5;
			cub3d->minimap.bottom_right_y = cub3d->minimap.top_left_y + 5;
			ft_draw_rectangle(cub3d);
			j++;
		}
		i++;
	}
}
