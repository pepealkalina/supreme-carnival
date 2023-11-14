/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/14 16:09:33 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

void	ft_free_file(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if(file[i][0] == '\n')
			free(file[i]);
		i++;
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

	atexit(&ft_leaks);
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
	cub3d->raycaster.map = ft_split(map, '\n');
	//ft_parse_map(cub3d);
	ft_load_textures(cub3d);
	ft_init_mlx(cub3d);
	ft_free_cub3d(cub3d);
	return (0);
}
