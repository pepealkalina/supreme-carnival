/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:17:06 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:17:26 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

int	ft_check_dup_rgb(const char **colors)
{
	int		i;
	int		j;
	char	**spliti;
	char	**splitj;

	i = -1;
	if (!colors)
		return (FALSE);
	while (colors[++i])
	{
		j = -1;
		spliti = ft_split(colors[i], ' ');
		while (colors[++j])
		{
			splitj = ft_split(colors[j], ' ');
			if (!ft_strncmp(spliti[0], splitj[0], 2) && i != j)
				return (ft_freevpp((void **)splitj), \
					ft_freevpp((void **)spliti), FALSE);
			ft_freevpp((void **)splitj);
		}
		ft_freevpp((void **)spliti);
	}
	return (TRUE);
}

static int	ft_check_one_of_each(const char **colors)
{
	int		i;
	int		colors_count;
	char	**split;

	i = 0;
	colors_count = 0;
	while (colors[i])
	{
		split = ft_split(colors[i], ' ');
		if (!ft_strncmp(split[0], "F", 2) && ft_pplen(split) == 2)
			colors_count++;
		if (!ft_strncmp(split[0], "C", 2) && ft_pplen(split) == 2)
			colors_count++;
		ft_freevpp((void **)split);
		i++;
	}
	if (colors_count < 2)
		return (FALSE);
	return (TRUE);
}

char	**ft_get_rgb(char **file)
{
	int		i;
	int		j;
	char	**saved_text;

	i = 0;
	saved_text = NULL;
	if (!file)
		return (NULL);
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] == 'F' && file[i][j + 1] == ' ')
				saved_text = ft_add_pp(file[i], saved_text);
			if (file[i][j] == 'C' && file[i][j + 1] == ' ')
				saved_text = ft_add_pp(file[i], saved_text);
			j++;
		}
		i++;
	}
	return (saved_text);
}

int	ft_parse_rgb(t_cub3d *cub3d)
{
	char	**colors;

	colors = ft_get_rgb(cub3d->file_content);
	if (!ft_check_dup_rgb((const char **)colors))
		return (ft_freevpp((void **)colors), FALSE);
	if (!ft_check_one_of_each((const char **)colors))
		return (ft_freevpp((void **)colors), FALSE);
	if (!ft_check_is_rgb((const char **)colors))
		return (ft_freevpp((void **)colors), FALSE);
	ft_save_rgb(cub3d, colors);
	ft_freevpp((void **)colors);
	return (TRUE);
}
