/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:52:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/04 11:27:15 by preina-g         ###   ########.fr       */
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

char	**ft_dup_map(char **map)
{
	int		i;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * ft_pplen(map));
	i = 0;
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	return (tmp);
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
	free(cub3d);
}
