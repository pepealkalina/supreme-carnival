/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:52:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/03 18:03:29 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_print_double(char **arr)
{
	int	j;

	j = 0;
	if (arr != NULL)
	{
		while (arr[j])
		{
			printf("pp[%d]: %s\n", j, arr[j]);
			j++;
		}
	}
}

/*free all malloc in cub3d*/
void	ft_free_cub3d(t_cub3d *cub3d)
{
	free(cub3d->file_parser->north);
	free(cub3d->file_parser->south);
	free(cub3d->file_parser->east);
	free(cub3d->file_parser->west);
	free(cub3d->file_parser->floor);
	free(cub3d->file_parser->ceiling);
	free(cub3d->file_parser);
	mlx_delete_image(cub3d->mlx, cub3d->img);
	mlx_terminate(cub3d->mlx);
	free(cub3d);
	exit(EXIT_SUCCESS);
}
