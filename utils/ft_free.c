/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:40:13 by paescano          #+#    #+#             */
/*   Updated: 2023/11/04 15:51:43 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_free_cub3d(t_cub3d *cub3d)
{
	free(cub3d->file_parser->north);
	free(cub3d->file_parser->south);
	free(cub3d->file_parser->east);
	free(cub3d->file_parser->west);
	free(cub3d->file_parser->floor);
	free(cub3d->file_parser->ceiling);
	free(cub3d->file_parser);
	free(cub3d);
	exit(EXIT_SUCCESS);
}

void	ft_exit_mlx(t_cub3d *cub3d)
{
	mlx_delete_image(cub3d->mlx, cub3d->img);
	mlx_terminate(cub3d->mlx);
	ft_free_cub3d(cub3d);
}
