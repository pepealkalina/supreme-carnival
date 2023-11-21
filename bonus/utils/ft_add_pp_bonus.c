/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:05:35 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:05:51 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

char	**ft_add_pp(char *arg, char **strs)
{
	char	**tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_pplen(strs) + 1;
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (perror(ERROR_MALLOC), NULL);
	tmp[len] = NULL;
	while (i < len - 1)
	{
		tmp[i] = strs[i];
		i++;
	}
	tmp[i] = arg;
	if (strs)
		free(strs);
	strs = tmp;
	return (strs);
}
