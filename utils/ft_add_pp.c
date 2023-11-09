/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:32:41 by paescano          #+#    #+#             */
/*   Updated: 2023/11/09 12:57:30 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
