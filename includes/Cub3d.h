/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:00:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/11/21 17:32:10 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <string.h>
# include <math.h>
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

/*define movement speed*/
# define MOVE_SPEED 0.15
# define ROTATION_SPEED 0.07

/*Colors*/
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF

typedef struct s_minimap
{
	int		top_left_x;
	int		top_left_y;
	int		bottom_right_x;
	int		bottom_right_y;
	int		color;
}t_minimap;

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

typedef struct s_raycaster
{
	char	**map;
	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	ray_len;
	int		line_height;
	int		line_start;
	int		line_end;
	int		tex_x;
}t_raycaster;

typedef struct cub3d
{
	t_minimap	minimap;
	t_raycaster	raycaster;
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
 * @brief erase the image, close the window and free the memory
 * of cub3d
 * 
 * @param cub3d data struct
 */
void	ft_exit_mlx(t_cub3d *cub3d);

/**
 * @brief print a string and exit the program
 * 
 * @param str string to free
 */
void	ft_exit(char *str);

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
 * @brief initialize the data of the player in the struct
 * 	raycaster
 * 
 * @param cub3d struct data
 */
void	ft_init_player(t_cub3d *cub3d);

/********************************/
/*			RAYCASTING			*/
/********************************/

/**
 * @brief execute the raycasting algorithm to draw the walls
 * 
 * @param cub3d struct data
 */
void	ft_raycasting(t_cub3d *cub3d);

/**
 * @brief calculate the position of the ray
 * 
 * @param cub3d struct data
 */
void	ft_pos_ray(t_cub3d *cub3d);

/**
 * @brief calculate the delta of the ray
 * 
 * @param cub3d struct data
 */

void	ft_delta_ray(t_cub3d *cub3d);

/**
 * @brief calculate the side of the ray
 * 
 * @param cub3d struct data
 */
void	ft_side_ray(t_cub3d *cub3d);

/**
 * @brief execute the DDA algorithm to calculate the length of the ray
 * 
 * @param cub3d struct data
 */
void	ft_dda(t_cub3d *cub3d);

/**
 * @brief calculate the length of the ray
 * 
 * @param cub3d struct data
 */
void	ft_len_ray(t_cub3d *cub3d);

/**
 * @brief calculate the height of the line to draw
 * 
 * @param cub3d struct data
 */
void	ft_line_height(t_cub3d *cub3d);

/**
 * @brief calculate the start of the line to draw
 * 
 * @param cub3d struct data
 */
void	ft_line_start(t_cub3d *cub3d);

/**
 * @brief calculate the end of the line to draw
 * 
 * @param cub3d struct data
 */
void	ft_line_end(t_cub3d *cub3d);

/**
 * @brief calculate the impact of the ray in the texture
 * 
 * @param cub3d struct data
 * @param texture texture to use
 */
void	ft_tex_impact(t_cub3d *cub3d, xpm_t *texture);

/**
 * @brief draw the line in the image
 * 
 * @param cub3d struct data
 * @param tex_xpm texture to use
 * @param tex_int texture in int ** format
 * @param pixel pixel to draw
 */
void	ft_draw_line(t_cub3d *cub3d, xpm_t *tex_xpm, int **tex_int, int pixel);

/****************************************/
/*			HANDLERS					*/
/****************************************/

/**
 * @brief load the textures and convert them to int ** and
 * save them in the struct in int ** format and xpm_t format
 * 
 * @param cub3d struct data
 */
void	ft_load_textures(t_cub3d *cub3d);

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
 * @brief rotate the player to the left
 * 
 * @param cub3d struct data
 */
void	ft_rotate_left(t_cub3d *cub3d);

/**
 * @brief rotate the player to the right
 * 
 * @param cub3d struct data
 */
void	ft_rotate_right(t_cub3d *cub3d);

/**
 * @brief move the player forward
 * 
 * @param cub3d struct data
 */
void	ft_move_forward(t_cub3d *cub3d);

/**
 * @brief move the player backward
 * 
 * @param cub3d struct data
 */
void	ft_move_backward(t_cub3d *cub3d);

/**
 * @brief move the player left
 * 
 * @param cub3d struct data
 */
void	ft_move_left(t_cub3d *cub3d);

/**
 * @brief move the player right
 * 
 * @param cub3d struct data
 */
void	ft_move_right(t_cub3d *cub3d);

/****************************************/
/*			PARSER						*/
/****************************************/

/**
 * @brief fill the map with spaces to make it a square
 * 
 * @param cub3d struct data
 */
void	ft_fill_map(t_cub3d *cub3d);

/**
 * @brief parse textures for it use
 * 
 * @param cub3d struct data
 */
int		ft_parse_textures(t_cub3d *cub3d);

/**
 * @brief parse rgb for it use
 * 
 * @param cub3d struct data
 */
int		ft_parse_rgb(t_cub3d *cub3d);

/**
 * @brief check if is a rgb color
 * 
 * @param colors colors for check
 */
int		ft_check_is_rgb(const char **colors);

/**
 * @brief save rgb
 * 
 * @param cub3d struct data
 * @param textures colors for save
 */
void	ft_save_rgb(t_cub3d *cub3d, char **textures);

/**
 * @brief save textures for the use
 * 
 * @param cub3d struct data
 * @param textures textures for save
 */
void	ft_save_textures(t_cub3d *cub3d, char **textures);

/**
 * @brief chek if the file is a .cub
 * 
 * @param file the file for chek
 */
int		ft_chec_if_cub(char *file);
/**
 * @brief parse map for it use
 * 
 * @param cub3d struct data
 */
int		ft_parse_map(t_cub3d *cub3d);

/**
 * @brief get the start position
 * 
 * @param start struct data
 * @param map map for check
 */
int		ft_get_start_pos(t_player *start, char **map);

/**
 * @brief aux fun for get map pos
 * 
 * @param start struct data
 * @param map line map for check
 * @param flag checker flag
 * @param line number of the line
 */
void	ft_sub_get_start_pos(t_player *start, \
		char *map, int *flag, int line);

/**
 * @brief reverse the map to parse it correctly
 * 
 * @param cub3d struct data
 */
void	ft_reverse_map(t_cub3d *cub3d);

/**
 * @brief check if the map is valid
 * 
 * @param cub3d struct data
 * @param map map for check
 */
int		ft_is_valid(t_cub3d *cub3d, t_map *map);

/**
 * @brief check if is a valid tile
 * 
 * @param map map for check
 */
int		ft_is_tile(char **map);

/**
 * @brief check if the map is closed
 * 
 * @param start struct data
 * @param map map for check
 */
int		is_map_closed(t_player *start, const char **map);

/**
 * @brief check if the tile is a border
 * 
 * @param map map for check
 * @param row the map row
 * @param col map col
 */
int		is_in_border(char **map, int row, int col);

#endif