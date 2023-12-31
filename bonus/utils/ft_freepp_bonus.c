/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:06:48 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:07:11 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

void	ft_freevpp(void **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
		free(pptr[i++]);
	free(pptr);
}
