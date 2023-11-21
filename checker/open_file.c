/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:36 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/21 17:32:50 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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

int	sub_is_valid_config(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] == '1' || line[i] == '0'
			|| line[i] == '\n')
			return (TRUE);
		else
			return (FALSE);
	}
	return (TRUE);
}

int	is_valid_config(char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (ft_strncmp(split_line[0], "NO", 2) == 0)
		return (ft_freevpp((void **)split_line), TRUE);
	else if (ft_strncmp(split_line[0], "SO", 2) == 0)
		return (ft_freevpp((void **)split_line), TRUE);
	else if (ft_strncmp(split_line[0], "WE", 2) == 0)
		return (ft_freevpp((void **)split_line), TRUE);
	else if (ft_strncmp(split_line[0], "EA", 2) == 0)
		return (ft_freevpp((void **)split_line), TRUE);
	else if (ft_strncmp(split_line[0], "F", 1) == 0)
		return (ft_freevpp((void **)split_line), TRUE);
	else if (ft_strncmp(split_line[0], "C", 1) == 0)
		return (ft_freevpp((void **)split_line), TRUE);
	else if (line[0] == '\n' || sub_is_valid_config(line))
		return (ft_freevpp((void **)split_line), TRUE);
	return (ft_freevpp((void **)split_line), FALSE);
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
		if (readmap && !is_valid_config(readmap))
			return (free(readmap), FALSE);
		if (!ft_add_line(cub3d, readmap))
			break ;
	}
	close (fd);
	return (TRUE);
}
