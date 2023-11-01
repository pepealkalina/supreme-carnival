# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 12:57:30 by preina-g          #+#    #+#              #
#    Updated: 2023/11/01 15:08:07 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

CFILES = main.c utils/utils_1.c utils/ft_add_pp.c utils/ft_pplen.c utils/ft_freepp.c \
		#checker/open_file.c checker/parse_textures.c

INCLUDES = -I ./includes

OBJECTS = $(CFILES:.c=.o)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJECTS)
	@echo $(G)Finished Compiling of [$(CFILES)]$(X)
	@echo
	@make -C libft -s
	@echo $(G)Finished Compiling of [libft]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) libft/libft.a -o $(NAME)
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

all: $(NAME)

clean:
	@$(RM) $(OBJECTS)
	@make clean -C libft -s
	@echo $(R)Removed libft objects$(X)
	@echo $(R)Removed following objects: [$(OBJECTS)]$(X)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft -s
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

norma:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES) ./includes

.PHONY: all clean fclean re norma
