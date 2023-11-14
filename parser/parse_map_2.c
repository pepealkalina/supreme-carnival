/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:47:29 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/14 15:44:52 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	ft_sub_get_start_pos(t_player *start, \
char *map, int *flag, int line)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i++])
	{
		if (map[i] != VOID)
		{
			if (map[i] == START_N || map[i] == START_S
				|| map[i] == START_E || map[i] == START_W)
			{
				if (*flag == 0)
				{
					start->pos_x = i;
					start->pos_y = line;
					start->direction = (char)map[i];
					map[i] = VOID;
				}
				*flag += 1;
			}
		}
	}
}
