/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:14:18 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:14:44 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

int	ft_chec_if_cub(char *file)
{
	if (ft_strncmp(file + (int)ft_strlen(file) - 4, ".cub", 4))
		return (FALSE);
	return (TRUE);
}
