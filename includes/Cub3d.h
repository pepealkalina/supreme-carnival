/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:00:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/03 18:01:20 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <string.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "error_messages.h"

/*define a bool*/
# define TRUE 1
# define FALSE 0

/*define window size*/
# define WIDTH 1280
# define HEIGHT 720

/*
	t_texture -> define the textures to use in every direction
*/
typedef struct s_rgb
{
	int32_t		red;
	int32_t		green;
	int32_t		blue;
	int32_t		hexa;
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
	mlx_t		*mlx;
	mlx_image_t	*img;
}t_cub3d;

/**
 * @brief read the file an return it for parser
 * 
 * @param file file to read
 * @return int
 */
int		ft_file_set_up(t_cub3d *cub3d, char **argv);

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

/**
 * @brief initialize the mlx pointer, hooks and window
 * 
 * @param cub3d data struct
 */
void	ft_init_mlx(t_cub3d *cub3d);

/**
 * @brief create a new image and load the background
 * 
 * @param cub3d data struct
 */
void	ft_load_background(t_cub3d *cub3d);

/**
 * @brief destroy the image and reload the background
 * with a new image
 * 
 * @param cub3d 
 */
void	ft_reload_background(t_cub3d *cub3d);

void	ft_free_cub3d(t_cub3d *cub3d);
int		ft_parse_textures(t_cub3d *cub3d);
t_cub3d	*ft_init_cub3d(void);
int		ft_parse_rgb(t_cub3d *cub3d);
int		ft_check_is_rgb(const char **colors);
void	ft_save_rgb(t_cub3d *cub3d, char **textures);
void	ft_save_textures(t_cub3d *cub3d, char **textures);
int		ft_chec_if_cub(char *file);

#endif