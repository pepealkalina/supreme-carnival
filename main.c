/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:57:28 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 15:11:13 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cub3d.h"

t_cub3d	*ft_init_cub3d(void)
{
	t_cub3d	*tmp;

	tmp = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!tmp)
		return (NULL);
	tmp->file_content = NULL;
	tmp->file_parser = (t_file *)malloc(sizeof(t_file));
	if (!tmp->file_parser)
	{
		free(tmp);
		return (NULL);
	}
	tmp->file_parser->file_lines = 0;
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = ft_init_cub3d();
	if (argc > 2)
		printf("Error\nToo many arguments");
	else
	{
		ft_file_set_up(cub3d, argv);
		ft_print_double(cub3d->file_content);
	}
	ft_free_cub3d(cub3d);
	return (0);
}
