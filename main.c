/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/14 17:01:28 by paescano         ###   ########.fr       */
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
	char	*map = "        1111111111111111111111111\n        1000000000110000000000001\n        1011000001110000000000001\n        1001000000000000000000001\n111111111011000001110000000000001\n100000000011000001110111111111111\n11110111111111011100000010001\n11110111111111011101010010001\n11000000110101011100000010001\n10000000000000001100000010001\n10000000000000001101010010001\n1100000111010101111101111000111\n11110111 1110101 101111010001\n11111111 1111111 111111111111";
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
	cub3d.raycaster.map = ft_split(map, '\n');
	//ft_parse_map(cub3d);
	ft_load_textures(&cub3d);
	ft_init_mlx(&cub3d);
	return (0);
}
