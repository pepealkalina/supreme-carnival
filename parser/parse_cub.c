/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:44:51 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:18 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	ft_chec_if_cub(char *file)
{
	if (ft_strncmp(file + (int)ft_strlen(file) - 4, ".cub", 4))
		return (FALSE);
	return (TRUE);
}
