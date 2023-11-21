/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:21:23 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:21:51 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_sub_parse_textures(char ***saved_text, char **file, int i)
{
	int	j;

	j = 0;
	while (file && file[i] && file[i][j])
	{
		if (file[i][j] == 'N' && file[i][j + 1] == 'O' && file[i][j + 2] == ' ')
			*saved_text = ft_add_pp(file[i], *saved_text);
		if (file[i][j] == 'S' && file[i][j + 1] == 'O' && file[i][j + 2] == ' ')
			*saved_text = ft_add_pp(file[i], *saved_text);
		if (file[i][j] == 'W' && file[i][j + 1] == 'E' && file[i][j + 2] == ' ')
			*saved_text = ft_add_pp(file[i], *saved_text);
		if (file[i][j] == 'E' && file[i][j + 1] == 'A' && file[i][j + 2] == ' ')
			*saved_text = ft_add_pp(file[i], *saved_text);
		j++;
	}
}

char	**ft_search_texture(char **file)
{
	char	**saved_text;
	int		i;

	saved_text = NULL;
	i = 0;
	while (file[i])
	{
		ft_sub_parse_textures(&saved_text, file, i);
		i++;
	}
	return (saved_text);
}

int	ft_check_dup_textures(const char **textures)
{
	int		i;
	int		j;
	char	**spliti;
	char	**splitj;

	i = 0;
	if (!textures)
		return (FALSE);
	while (textures[i])
	{
		j = 0;
		spliti = ft_split(textures[i], ' ');
		while (textures[j])
		{
			splitj = ft_split(textures[j], ' ');
			if (!ft_strncmp(spliti[0], splitj[0], 2) && i != j)
				return (ft_freevpp((void **)splitj), \
					ft_freevpp((void **)spliti), FALSE);
			ft_freevpp((void **)splitj);
			j++;
		}
		ft_freevpp((void **)spliti);
		i++;
	}
	return (TRUE);
}

int	ft_check_one_of_each(const char **textures)
{
	int		i;
	int		textures_count;
	char	**split;

	i = -1;
	textures_count = 0;
	while (textures[++i])
	{
		split = ft_split(textures[i], ' ');
		if (!ft_strncmp(split[0], "NO", 2))
			textures_count++;
		if (!ft_strncmp(split[0], "SO", 2))
			textures_count++;
		if (!ft_strncmp(split[0], "WE", 2))
			textures_count++;
		if (!ft_strncmp(split[0], "EA", 2))
			textures_count++;
		ft_freevpp((void **)split);
	}
	if (textures_count != 4)
		return (FALSE);
	return (TRUE);
}

int	ft_parse_textures(t_cub3d *cub3d)
{
	char	**textures;

	textures = ft_search_texture(cub3d->file_content);
	if (!ft_check_dup_textures((const char **)textures))
		return (ft_freevpp((void **)textures), FALSE);
	if (!ft_check_one_of_each((const char **)textures))
		return (ft_freevpp((void **)textures), FALSE);
	ft_save_textures(cub3d, textures);
	ft_freevpp((void **)textures);
	return (TRUE);
}
