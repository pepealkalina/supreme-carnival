/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:00:31 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 16:53:34 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

char	**ft_search_texture(char **file)
{
	char	**saved_text;
	int		i;
	int		j;

	saved_text = NULL;
	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == 'N' && file[i][j + 1] == 'O')
				saved_text = ft_add_pp(file[i], saved_text);
			if (file[i][j] == 'S' && file[i][j + 1] == 'O')
				saved_text = ft_add_pp(file[i], saved_text);
			if (file[i][j] == 'W' && file[i][j + 1] == 'E')
				saved_text = ft_add_pp(file[i], saved_text);
			if (file[i][j] == 'E' && file[i][j + 1] == 'A')
				saved_text = ft_add_pp(file[i], saved_text);
			j++;
		}
		i++;
	}
	return (saved_text);
}

int	ft_parse_textures(t_cub3d *cub3d)
{
	char	**textures;

	textures = ft_search_texture(cub3d->file_content);
	ft_print_double(textures);
	return (0);
}
