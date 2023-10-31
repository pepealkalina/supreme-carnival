# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 12:57:30 by preina-g          #+#    #+#              #
#    Updated: 2023/10/31 14:58:23 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CHECKER = open_file.c

PARSER = parse_textures.c

SRC = main.c utils/utils_1.c checker/$(CHECKER)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft -s
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)

clean:
	@make clean -C libft -s
	rm -rf *.o

fclean:
	@make fclean -C libft -s
	rm -rf *.o $(NAME)

re: fclean all

.PHONY: fclean all clean re