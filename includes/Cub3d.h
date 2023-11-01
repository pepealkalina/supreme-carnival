/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:00:54 by preina-g          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/01 14:39:50 by preina-g         ###   ########.fr       */
=======
/*   Updated: 2023/11/01 12:44:44 by paescano         ###   ########.fr       */
>>>>>>> e4d1c74f4c5b3a2b88e0506de23148ed06bbbfa2
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
}t_file;

typedef struct cub3d
{
	t_file		*file_parser;
	char		**file_content;
	int			file_lines;
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
char	**ft_add_pp(char *arg, char **strs);
int		ft_pplen(char **pp);

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

#endif