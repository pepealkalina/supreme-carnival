/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:20 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/03 11:19:23 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_check_dup_rgb(const char **colors)
{
	int	i;
	int	j;

	i = 0;
	if (!colors)
		return (FALSE);
	while (colors[i])
	{
		j = 0;
		while (colors[j])
		{
			if (!ft_strncmp(ft_split(colors[i], ' ')[0], \
				ft_split(colors[j], ' ')[0], 2) && i != j)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	ft_check_one_of_each(const char **colors)
{
	int	i;
	int	colors_count;

	i = 0;
	colors_count = 0;
	while (colors[i])
	{
		if (!ft_strncmp(ft_split(colors[i], ' ')[0], "F", 2))
			colors_count++;
		if (!ft_strncmp(ft_split(colors[i], ' ')[0], "C", 2))
			colors_count++;
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
		return (FALSE);
	if (!ft_check_one_of_each((const char **)colors))
		return (FALSE);
	if (!ft_check_is_rgb((const char **)colors))
		return (FALSE);
	ft_save_rgb(cub3d, colors);
	ft_freevpp((void **)colors);
	return (TRUE);
}
