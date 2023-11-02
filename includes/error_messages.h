/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:21:26 by paescano          #+#    #+#             */
/*   Updated: 2023/11/02 11:38:24 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define ERROR_MALLOC "\033[31mError\nMalloc failed\033[0m\n"
# define TEXTURE_USAGE "[!]The correct Format is:\n\t\
NO <texture_path>\n\tSO <texture_path>\
\n\tEA <texture_path>\n\tWE <texture_path>\n"
# define RGB_USAGE "[!]The correct Format is:\n\t\
C <red>,<green>,<blue>\n\tF <red>,<green>,<blue>\n"

#endif