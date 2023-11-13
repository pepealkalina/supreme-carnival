/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/13 15:15:38 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

void	ft_free_file(char **file)
{
	int	i;

	i = 0;
	while (file[i++])
	{
		if (ft_strlen(file[i]) == 1)
			free(file[i]);
	}
	free(file);
}

void	ft_leaks(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	//atexit(&ft_leaks);
	//cub3d = ft_init_cub3d();
	if (argc > 2)
		printf("Error\nToo many arguments");
	else
	{
		if (!ft_file_set_up(&cub3d, argv))
			exit(printf("Error\n[-]Wrong file format\n"));
		if (!ft_parse_textures(&cub3d))
		{
			//ft_freevpp((void **)cub3d.file_content);
			exit(printf("Error\n[-]Wrong textures Format!!\n[!]The correct Format is:\n\t\
NO <texture_path>\n\t\
SO <texture_path>\n\t\
EA <texture_path>\n\t\
WE <texture_path>\n"));
		}
		if (!ft_parse_rgb(&cub3d))
		{
			//ft_freevpp((void *)cub3d.file_content);
			//ft_free_cub3d(&cub3d);
			exit(printf("Error\n[-]Wrong RGB Format!!\n[!]The correct Format is:\n\t\
C <red>,<green>,<blue>\n\t\
F <red>,<green>,<blue>\n"));
		}
	}
	if (!ft_parse_map(&cub3d))
	{
		//ft_freevpp((void *)cub3d.file_content);
		exit(printf("Error\n[-]Wrong Map Format!!"));
	}
	//ft_init_mlx(&cub3d);
	ft_free_file(cub3d.file_content);

	//printf("ceiling -> %X\n", cub3d.file_parser.ceiling.hexa);
	//printf("floor -> %X\n", cub3d.file_parser.floor.hexa);
	//printf("north -> %s\n", cub3d.file_parser.north.file);
	//printf("south -> %s\n", cub3d.file_parser.south.file);
	//printf("west -> %s\n", cub3d.file_parser.west.file);
	//printf("east -> %s\n", cub3d.file_parser.east.file);
	//ft_printpp(cub3d.file_parser.map.map_content);
	free(cub3d.file_parser.north.direction);
	free(cub3d.file_parser.south.direction);
	free(cub3d.file_parser.east.direction);
	free(cub3d.file_parser.west.direction);
	free(cub3d.file_parser.north.file);
	free(cub3d.file_parser.south.file);
	free(cub3d.file_parser.east.file);
	free(cub3d.file_parser.west.file);
	ft_freevpp((void *)cub3d.file_parser.map.map_content);
	return (0);
}
