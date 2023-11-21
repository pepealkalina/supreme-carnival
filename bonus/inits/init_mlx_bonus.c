/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:23:11 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:23:27 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *) param;
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_move_forward(cub3d);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_move_backward(cub3d);
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_move_left(cub3d);
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_move_right(cub3d);
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_rotate_left(cub3d);
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_rotate_right(cub3d);
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		ft_exit_mlx(cub3d);
}

void	ft_init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!cub3d->mlx)
		exit (EXIT_FAILURE);
	mlx_key_hook(cub3d->mlx, &ft_keyhook, (void *) cub3d);
	mlx_close_hook(cub3d->mlx, (void *) &ft_exit_mlx, (void *) cub3d);
	ft_load_background(cub3d);
	ft_init_player(cub3d);
	ft_raycasting(cub3d);
	mlx_loop(cub3d->mlx);
	ft_exit_mlx(cub3d);
}
