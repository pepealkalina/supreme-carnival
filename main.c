/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/02 17:22:26 by preina-g         ###   ########.fr       */
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
		if (!ft_file_set_up(cub3d, argv))
			exit(printf("Error\n[-]Wrong file format\n"));
		if (!ft_parse_textures(cub3d))
		{
			ft_free_cub3d(cub3d);
			exit(printf("Error\n[-]Wrong textures Format!!\n[!]The correct Format is:\n\t\
NO <texture_path>\n\t\
SO <texture_path>\n\t\
EA <texture_path>\n\t\
WE <texture_path>\n"));
		}
		if (!ft_parse_rgb(cub3d))
		{
			ft_free_cub3d(cub3d);
			exit(printf("Error\n[-]Wrong RGB Format!!\n[!]The correct Format is:\n\t\
C <red>,<green>,<blue>\n\t\
F <red>,<green>,<blue>\n"));
		}
	}
	printf("NO-> %s\nSO-> %s\nWE-> %s\nEA-> %s\nFr-> %d\nFg-> %d\nFb-> %d\nFh-> %X\nCr-> %d\nCg-> %d\nCb-> %d\nCh-> %X\n", cub3d->file_parser->north->file, cub3d->file_parser->south->file, cub3d->file_parser->west->file, cub3d->file_parser->east->file,  cub3d->file_parser->floor->red, cub3d->file_parser->floor->green, cub3d->file_parser->floor->blue, cub3d->file_parser->floor->hexa, cub3d->file_parser->ceiling->red, cub3d->file_parser->ceiling->green, cub3d->file_parser->ceiling->blue, cub3d->file_parser->ceiling->hexa);
	ft_free_cub3d(cub3d);
	return (0);
}
