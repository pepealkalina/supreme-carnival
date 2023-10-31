/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/10/31 15:21:16 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

int	main(int argc, char **argv)
{
	char	**file;

	if (argc > 2)
		printf("Error\nToo many arguments");
	else
	{
		file = ft_read_file(argv[1]);
		ft_print_double(file);
	}
	return (0);
}
