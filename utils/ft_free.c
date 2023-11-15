/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:40:13 by paescano          #+#    #+#             */
/*   Updated: 2023/11/15 13:09:29 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_free_cub3d(t_cub3d *cub3d)
{
	(void)cub3d;
	exit(EXIT_SUCCESS);
}

void	ft_exit_mlx(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->img);
	mlx_terminate(cub3d->mlx);
	ft_free_cub3d(cub3d);
}
