/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:29:03 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:29:09 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static int	**ft_xpm_to_intpp(xpm_t *tex)
{
	int	**tmp;
	int	i;
	int	j;

	tmp = ft_calloc(sizeof(int *), tex->texture.height + 1);
	i = 4;
	while (i < (int)tex->texture.height + 4)
	{
		j = 4;
		tmp[i - 4] = ft_calloc(sizeof(int), tex->texture.width);
		while (j < (int)tex->texture.width + 4)
		{
			tmp[i - 4][j - 4] = ft_rgba_to_hex(tex->texture.pixels[
					(tex->texture.width * 4 * (i - 4)) + (4 * (j - 4)) + 0],
					tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 1],
					tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 2],
					tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 3]);
			j++;
		}
		i++;
	}
	return (tmp);
}

void	ft_load_textures(t_cub3d *cub3d)
{
	cub3d->file_parser.north.tex_xpm = mlx_load_xpm42(
			cub3d->file_parser.north.file);
	if (!cub3d->file_parser.north.tex_xpm)
		ft_exit(ERROR_TEXTURES);
	cub3d->file_parser.south.tex_xpm = mlx_load_xpm42(
			cub3d->file_parser.south.file);
	if (!cub3d->file_parser.south.tex_xpm)
		ft_exit(ERROR_TEXTURES2);
	cub3d->file_parser.east.tex_xpm = mlx_load_xpm42(
			cub3d->file_parser.east.file);
	if (!cub3d->file_parser.east.tex_xpm)
		ft_exit(ERROR_TEXTURES4);
	cub3d->file_parser.west.tex_xpm = mlx_load_xpm42(
			cub3d->file_parser.west.file);
	if (!cub3d->file_parser.west.tex_xpm)
		ft_exit(ERROR_TEXTURES3);
	cub3d->file_parser.north.tex_int = ft_xpm_to_intpp(
			cub3d->file_parser.north.tex_xpm);
	cub3d->file_parser.south.tex_int = ft_xpm_to_intpp(
			cub3d->file_parser.south.tex_xpm);
	cub3d->file_parser.east.tex_int = ft_xpm_to_intpp(
			cub3d->file_parser.east.tex_xpm);
	cub3d->file_parser.west.tex_int = ft_xpm_to_intpp(
			cub3d->file_parser.west.tex_xpm);
}
