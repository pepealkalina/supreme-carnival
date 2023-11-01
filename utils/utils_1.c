/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:52:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 15:08:59 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_print_double(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
}

/*free all malloc in cub3d*/
void	ft_free_cub3d(t_cub3d *cub3d)
{
	free(cub3d->file_parser);
	free(cub3d);
}
