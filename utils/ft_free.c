/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:40:13 by paescano          #+#    #+#             */
/*   Updated: 2023/11/14 16:56:08 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_free_cub3d(t_cub3d *cub3d)
{
	free(cub3d);
	exit(EXIT_SUCCESS);
}

void	ft_exit_mlx(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->img);
	mlx_terminate(cub3d->mlx);
	ft_free_cub3d(cub3d);
}
