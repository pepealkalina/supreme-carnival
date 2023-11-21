/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:06:22 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:06:27 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_exit(char *str)
{
	printf("%s", str);
	exit(EXIT_SUCCESS);
}

void	ft_exit_mlx(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->img);
	mlx_terminate(cub3d->mlx);
	exit(EXIT_SUCCESS);
}
