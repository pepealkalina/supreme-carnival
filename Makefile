# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 12:57:30 by preina-g          #+#    #+#              #
#    Updated: 2023/11/01 18:01:46 by preina-g         ###   ########.fr        #
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

CFILES = main.c init_cub3d.c utils/utils_1.c utils/ft_add_pp.c utils/ft_pplen.c utils/ft_freepp.c \
		checker/open_file.c parser/parse_textures.c parser/parse_textures_2.c

INCLUDES = -I ./includes -I ./MLX42/include/MLX42 

LIBS = libft/libft.a MLX42/libmlx42.a -ldl -lglfw -pthread -lm -L"/Users/$(USER)/.brew/opt/glfw/lib/"

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
	@make -s all -C MLX42
	@echo $(G)Finished Compiling of [MLX42]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBS) -o $(NAME)
	@echo $(G)Finished Compiling of [$(NAME)]$(X)

all: $(NAME)

clean:
	@make clean -C libft -s
	@echo $(R)Removed libft objects$(X)
	@make clean -C MLX42 -s
	@echo $(R)Removed MLX42 objects$(X)
	@$(RM) $(OBJECTS)
	@echo $(R)Removed following objects: [$(OBJECTS)]$(X)

fclean: clean
	@make fclean -C libft -s
	@echo $(R)Removed following executable: [libft.a]$(X)
	@make fclean -C MLX42 -s
	@echo $(R)Removed following executable: [MLX42.a]$(X)
	@$(RM) $(NAME)
	@echo $(R)Removed following executable: [$(NAME)]$(X)

re: fclean all

norma:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES) ./includes

.PHONY: all clean fclean re norma
