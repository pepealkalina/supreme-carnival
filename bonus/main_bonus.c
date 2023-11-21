/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:04:35 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 17:33:20 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static void	ft_free_file(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i][0] == '\n')
			free(file[i]);
		i++;
	}
	free(file);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		ft_exit(ERROR_ARGS);
	if (!ft_file_set_up(&cub3d, argv))
		ft_exit(ERROR_FILE);
	if (!ft_parse_textures(&cub3d))
		ft_exit(ERROR_TX ERROR_TX2 ERROR_TX3 ERROR_TX4);
	if (!ft_parse_rgb(&cub3d))
		ft_exit(ERROR_RGB ERROR_RGB2 ERROR_RGB3);
	if (!ft_parse_map(&cub3d))
		ft_exit(ERROR_MAP);
	ft_free_file(cub3d.file_content);
	ft_load_textures(&cub3d);
	ft_init_mlx(&cub3d);
}
