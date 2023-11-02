/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:48:39 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/02 13:02:30 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_checknum(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]) && rgb[i][j] != '\n')
				return (FALSE);
			j++;
		}
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	ft_check_is_rgb(const char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (!ft_checknum(ft_split(ft_split(colors[i], ' ')[1], ',')))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
