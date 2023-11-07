/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:48:35 by paescano          #+#    #+#             */
/*   Updated: 2023/11/07 14:53:04 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

static void	background_3d(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < (HEIGHT / 2))
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put_pixel(cub3d->img, j, i, cub3d->file_parser.ceiling.hexa);
		i++;
	}
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put_pixel(cub3d->img, j, i, cub3d->file_parser.floor.hexa);
		i++;
	}
}

void	ft_load_background(t_cub3d *cub3d)
{
	cub3d->img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub3d->mlx, cub3d->img, 0, 0);
	background_3d(cub3d);
}

void	ft_reload_background(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->img);
	ft_load_background(cub3d);
}
