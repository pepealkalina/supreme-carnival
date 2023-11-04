/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:44:51 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/02 17:20:43 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_chec_if_cub(char *file)
{
	int		len_split;
	char	**split_path;

	split_path = ft_split(file, '.');
	len_split = ft_pplen(split_path);
	if (ft_strlen(split_path[len_split - 1]) != 3)
		return (FALSE);
	else if (ft_strncmp(split_path[len_split - 1], "cub", 3))
		return (FALSE);
	return (TRUE);
}