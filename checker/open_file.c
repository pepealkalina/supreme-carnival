/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:36 by preina-g          #+#    #+#             */
/*   Updated: 2023/10/31 15:27:47 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

char	**ft_read_file(char *file)
{
	char	**map;
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		map_tmp = tmp;
		tmp = ft_strjoin(map_tmp, line);
		free(line);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}
