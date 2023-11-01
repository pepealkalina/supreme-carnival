/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:00:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/01 16:00:13 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <string.h>
# include "../libft/libft.h"
# include "error_messages.h"

/*define a bool*/
# define TRUE 1
# define FALSE 0
/*
	t_texture -> define the textures to use in every direction
*/
typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}t_rgb;
/*
	t_rgb -> define rgb colors in floor and ceiling
*/
typedef struct s_texture
{
	char	*direction;
	char	*file;
}t_texture;

/*
	t_texture -> define the textures to use in every direction
	t_rgb -> define rgb colors in floor and ceiling
*/
typedef struct s_file
{
	t_texture	*north;
	t_texture	*south;
	t_texture	*east;
	t_texture	*west;

	t_rgb		*floor;
	t_rgb		*ceiling;
	int			file_lines;
}t_file;

typedef struct cub3d
{
	t_file		*file_parser;
	char		**file_content;
}t_cub3d;

/**
 * @brief read the file an return it for parser
 * 
 * @param file file to read
 * @return char**
 */
void	ft_file_set_up(t_cub3d *cub3d, char **argv);

/**
 * @brief print a char**
 * 
 * @param arr array for printing
 */
void	ft_print_double(char **arr);

/**
 * @brief frees the memory of a null terminated char **
 * 
 * @param pptr the string array to free
*/
void	ft_freevpp(void **pptr);

/**
 * @brief creates a new string concatenating 2 strings
 * 
 * @param s1 the first string
 * @param s2 the second string
*/
int		ft_pplen(char **pp);

/**
 * @brief adds a string to a null terminated char **
 * 
 * @param arg string to add
 * @param strs string array
 * @return char** string array with the new string
 */
char	**ft_add_pp(char *arg, char **strs);

void	ft_free_cub3d(t_cub3d *cub3d);
int		ft_parse_textures(t_cub3d *cub3d);
t_cub3d	*ft_init_cub3d(void);

#endif