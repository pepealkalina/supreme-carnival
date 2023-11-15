/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:21:26 by paescano          #+#    #+#             */
/*   Updated: 2023/11/15 17:25:26 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

/********************************/
/*		Colors					*/
/********************************/

# define RED_CMD "\033[31m"
# define NOCOLOR_CMD "\033[0m"

/********************************/
/*		Messages Errors			*/
/********************************/

# define ERROR_MALLOC "\033[31mError\nMalloc failed\033[0m\n"
# define ERROR_TEXTURES "\033[31mError\nCant load the NO texture\033[0m\n"
# define ERROR_TEXTURES2 "\033[31mError\nCant load the SO texture\033[0m\n"
# define ERROR_TEXTURES3 "\033[31mError\nCant load the WE texture\033[0m\n"
# define ERROR_TEXTURES4 "\033[31mError\nCant load the EA texture\033[0m\n"
# define ERROR_MAP "\033[31mError\nWrong map format\033[0m\n"
# define ERROR_ARGS "\033[31mError\nWrong number of arguments, only 2\033[0m\n"
# define ERROR_FILE "\033[31mError\nWrong file format\033[0m\n"
# define ERROR_TX "\033[31mError\nWrong textures format\n"
# define ERROR_TX2 "The correct Format is:\n\tNO <texture_path>\n"
# define ERROR_TX3 "\tSO <texture_path>\n\tEA <texture_path>\n"
# define ERROR_TX4 "\tWE <texture_path>\033[0m\n"
# define ERROR_RGB "\033[31mError\nWrong RGB format\n"
# define ERROR_RGB2 "The correct Format is:\n\tC <red>,<green>,<blue>\n\t"
# define ERROR_RGB3 "F <red>,<green>,<blue>\033[0m\n"

#endif