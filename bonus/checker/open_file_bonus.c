/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:29:34 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 12:29:44 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d_bonus.h"

static int	ft_add_line(t_cub3d *cub3d, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	cub3d->file_parser.file_lines++;
	tmp = (char **)malloc(sizeof(char *) * \
		(cub3d->file_parser.file_lines + 1));
	if (!tmp)
		return (0);
	tmp[cub3d->file_parser.file_lines] = NULL;
	while (i < cub3d->file_parser.file_lines - 1)
	{
		tmp[i] = cub3d->file_content[i];
		i++;
	}
	tmp[i] = line;
	if (cub3d->file_content)
		free(cub3d->file_content);
	cub3d->file_content = tmp;
	return (1);
}

int	ft_file_set_up(t_cub3d *cub3d, char **argv)
{
	char	*readmap;
	int		fd;

	if (!ft_chec_if_cub(argv[1]))
		return (FALSE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (FALSE);
	cub3d->file_content = NULL;
	while (1)
	{
		readmap = get_next_line(fd);
		if (!ft_add_line(cub3d, readmap))
			break ;
	}
	close (fd);
	return (TRUE);
}
