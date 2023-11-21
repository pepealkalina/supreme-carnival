/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:09:33 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:09:49 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static double	ft_calculate_step(t_cub3d *cub3d, xpm_t *tex_xpm)
{
	double	step;

	step = 1.0 * tex_xpm->texture.height / cub3d->raycaster.line_height;
	return (step);
}

static double	ft_calculate_tex_pos(t_cub3d *cub3d, double step)
{
	double	tex_pos;

	tex_pos = ((double)cub3d->raycaster.line_start
			- (double)HEIGHT / 2
			+ (double)cub3d->raycaster.line_height / 2) * step;
	if (tex_pos < 0)
		tex_pos = 0;
	return (tex_pos);
}

void	ft_draw_line(t_cub3d *cub3d, xpm_t *tex_xpm, int **tex_int, int pixel)
{
	int				tex_y;
	double			tex_pos;
	double			step;
	int				screen_y;

	step = ft_calculate_step(cub3d, tex_xpm);
	tex_pos = ft_calculate_tex_pos(cub3d, step);
	screen_y = cub3d->raycaster.line_start;
	while (screen_y < cub3d->raycaster.line_end)
	{
		tex_y = (int)tex_pos;
		mlx_put_pixel(cub3d->img, pixel, screen_y,
			tex_int[tex_y][cub3d->raycaster.tex_x]);
		if (tex_pos > tex_xpm->texture.height - 1)
			tex_pos = tex_xpm->texture.height - 1;
		tex_pos = tex_pos + step;
		screen_y++;
	}
}
