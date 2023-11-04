/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:43 by paescano          #+#    #+#             */
/*   Updated: 2023/11/04 16:07:01 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
