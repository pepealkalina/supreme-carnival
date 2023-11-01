/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 14:36:14 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc > 2)
		printf("Error\nToo many arguments");
	else
	{
		cub3d.file_lines = 0;
		ft_map_set_up(&cub3d, argv);
		ft_print_double(cub3d.file_content);
	}
	return (0);
}
