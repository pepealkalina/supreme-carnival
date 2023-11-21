/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:13:15 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:13:29 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static void	ft_calculate_draw_line(t_cub3d *cub3d, int pixel)
{
	if (cub3d->raycaster.side == 0)
	{
		ft_tex_impact(cub3d, cub3d->file_parser.east.tex_xpm);
		ft_draw_line(cub3d, cub3d->file_parser.east.tex_xpm,
			cub3d->file_parser.east.tex_int, pixel);
	}
	if (cub3d->raycaster.side == 1)
	{
		ft_tex_impact(cub3d, cub3d->file_parser.west.tex_xpm);
		ft_draw_line(cub3d, cub3d->file_parser.west.tex_xpm,
			cub3d->file_parser.west.tex_int, pixel);
	}
	if (cub3d->raycaster.side == 2)
	{
		ft_tex_impact(cub3d, cub3d->file_parser.south.tex_xpm);
		ft_draw_line(cub3d, cub3d->file_parser.south.tex_xpm,
			cub3d->file_parser.south.tex_int, pixel);
	}
	if (cub3d->raycaster.side == 3)
	{
		ft_tex_impact(cub3d, cub3d->file_parser.north.tex_xpm);
		ft_draw_line(cub3d, cub3d->file_parser.north.tex_xpm,
			cub3d->file_parser.north.tex_int, pixel);
	}
}

void	ft_raycasting(t_cub3d *cub3d)
{
	double	pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		cub3d->raycaster.camera_x = 2 * pixel / WIDTH - 1;
		ft_pos_ray(cub3d);
		ft_delta_ray(cub3d);
		ft_side_ray(cub3d);
		ft_dda(cub3d);
		ft_len_ray(cub3d);
		ft_line_height(cub3d);
		ft_line_start(cub3d);
		ft_line_end(cub3d);
		ft_calculate_draw_line(cub3d, pixel);
		pixel++;
	}
	ft_draw_minimap(cub3d);
}
