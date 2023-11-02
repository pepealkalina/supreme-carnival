/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/02 11:38:54 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = ft_init_cub3d();
	if (argc > 2)
		printf("Error\nToo many arguments");
	else
	{
		ft_file_set_up(cub3d, argv);
		if (!ft_parse_textures(cub3d))
		{
			ft_free_cub3d(cub3d);
			exit(printf("Error\n[-]Wrong textures Format!!\n%s", \
			TEXTURE_USAGE));
		}
		if (!ft_parse_rgb(cub3d))
		{
			ft_free_cub3d(cub3d);
			exit(printf("Error\n[-]Wrong RGB Format!!\n%s", \
			RGB_USAGE));
		}
	}
	ft_free_cub3d(cub3d);
	return (0);
}
