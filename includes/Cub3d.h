/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:00:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/08 15:34:41 by preina-g         ###   ########.fr       */
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

/*define tiles*/
# define WALL '1'
# define VOID '0'
# define START_N 'N'
# define START_S 'S'
# define START_E 'E'
# define START_W 'W'

/*define window size*/
# define WIDTH 1280
# define HEIGHT 720

/*
	t_rgb -> define rgb colors in floor and ceiling
*/
typedef struct s_rgb
{
	int		hexa;
}t_rgb;

/*
	t_texture -> define the textures to use in every direction
*/
typedef struct s_texture
{
	char	*direction;
	char	*file;
	xpm_t	*tex_xpm;
	int		**tex_int;
}t_texture;

typedef struct s_player
{
	char	direction;
	int		pos_x;
	int		pos_y;
}t_player;

typedef struct s_map
{
	t_player	start;
	int			max_heigth;
	int			max_with;
	char		**map_content;
}t_map;

/*
	t_texture -> define the textures to use in every direction
	t_rgb -> define rgb colors in floor and ceiling
*/
typedef struct s_file
{
	t_map		map;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;

	t_rgb		floor;
	t_rgb		ceiling;
	int			file_lines;
}t_file;

typedef struct cub3d
{
	t_file		file_parser;
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
 * @param pp array for printing
 */
void	ft_printpp(char **pp);

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
 * @brief duplicates a char **
 * 
 * @param pp char ** to duplicate
 * @return char** copy of pp
 */
char	**ft_ppdup(char **pp);

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

/**
 * @brief free the memory of cub3d
 * 
 * @param cub3d data struct
 */
void	ft_free_cub3d(t_cub3d *cub3d);

/**
 * @brief erase the image, close the window and free the memory
 * of cub3d
 * 
 * @param cub3d data struct
 */
void	ft_exit_mlx(t_cub3d *cub3d);

/**
 * @brief convert a rgba color to hex color
 * 
 * @param r red
 * @param g green
 * @param b blue
 * @param a opacity
 * @return int hex color
 */
int		ft_rgba_to_hex(int r, int g, int b, int a);

/**
 * @brief load the textures and convert them to int ** and
 * save them in the struct in int ** format and xpm_t format
 * 
 * @param cub3d struct data
 */
void	load_textures(t_cub3d *cub3d);

int		ft_parse_textures(t_cub3d *cub3d);
t_cub3d	*ft_init_cub3d(void);
int		ft_parse_rgb(t_cub3d *cub3d);
int		ft_check_is_rgb(const char **colors);
void	ft_save_rgb(t_cub3d *cub3d, char **textures);
void	ft_save_textures(t_cub3d *cub3d, char **textures);
int		ft_chec_if_cub(char *file);
int		ft_parse_map(t_cub3d *cub3d);
void	ft_sub_get_start_pos(t_player *start, \
		const char *map, int *flag, int line);
int		ft_sub_is_closed(char *line, char **map, int nline);

#endif