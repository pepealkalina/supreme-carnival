/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppdup_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:07:51 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:07:56 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

char	**ft_ppdup(char **pp)
{
	int		i;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * ft_pplen(pp));
	i = 0;
	while (pp[i])
	{
		tmp[i] = ft_strdup(pp[i]);
		i++;
	}
	return (tmp);
}
