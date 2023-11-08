/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:54:43 by paescano          #+#    #+#             */
/*   Updated: 2023/11/08 12:51:07 by preina-g         ###   ########.fr       */
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
