# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 12:57:30 by preina-g          #+#    #+#              #
#    Updated: 2023/11/21 17:44:30 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"

CFILES = main.c utils/ft_free.c utils/ft_add_pp.c utils/ft_pplen.c utils/ft_freepp.c \
		checker/open_file.c parser/parse_textures.c parser/parse_textures_2.c parser/parse_rgb.c \
		parser/parse_rgb_2.c parser/parse_cub.c inits/init_mlx.c handlers/handler_background.c \
		parser/parse_map.c parser/parse_map_2.c utils/ft_printpp.c utils/ft_ppdup.c \
		handlers/handler_textures.c inits/init_player.c raycasting/raycasting.c \
		raycasting/pos_len_ray.c raycasting/ft_dda.c raycasting/pos_len_line.c \
		raycasting/extract_line_tex.c raycasting/draw_line.c handlers/handler_camera.c \
		handlers/handler_moves.c parser/parse_map_3.c

CFILES_BONUS = bonus/main_bonus.c bonus/utils/ft_free_bonus.c bonus/utils/ft_add_pp_bonus.c \
		bonus/utils/ft_pplen_bonus.c bonus/utils/ft_freepp_bonus.c bonus/checker/open_file_bonus.c \
		bonus/parser/parse_textures_bonus.c bonus/parser/parse_textures_2_bonus.c bonus/parser/parse_rgb_bonus.c \
		bonus/parser/parse_rgb_2_bonus.c bonus/parser/parse_cub_bonus.c bonus/inits/init_mlx_bonus.c \
		bonus/handlers/handler_background_bonus.c bonus/parser/parse_map_bonus.c bonus/parser/parse_map_2_bonus.c \
		bonus/utils/ft_printpp_bonus.c bonus/utils/ft_ppdup_bonus.c bonus/handlers/handler_textures_bonus.c \
		bonus/inits/init_player_bonus.c bonus/raycasting/raycasting_bonus.c bonus/raycasting/pos_len_ray_bonus.c \
		bonus/raycasting/ft_dda_bonus.c bonus/raycasting/pos_len_line_bonus.c bonus/raycasting/extract_line_tex_bonus.c \
		bonus/raycasting/draw_line_bonus.c bonus/handlers/handler_camera_bonus.c bonus/handlers/handler_moves_bonus.c \
		bonus/handlers/handler_minimap_bonus.c bonus/parser/parse_map_3_bonus.c

INCLUDES = -I ./includes -I ./MLX42/include/MLX42

INCLUDES_BONUS = -I ./bonus/includes -I ./MLX42/include/MLX42

LIBS = libft/libft.a MLX42/libmlx42.a -ldl -lglfw -pthread -lm -L"/Users/$(USER)/.brew/opt/glfw/lib/"

OBJECTS = $(CFILES:.c=.o)

OBJECTS_BONUS = $(CFILES_BONUS:.c=.o)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJECTS)
	@echo $(G)Finished Compiling of [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [libft]...$(X)
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

$(NAME_BONUS): $(OBJECTS_BONUS)	
	@echo $(G)Finished Compiling of [$(CFILES_BONUS)]$(X)
	@echo
	@echo $(Y)Compiling [libft]...$(X)
	@make -C libft -s
	@echo $(G)Finished Compiling of [libft]$(X)
	@echo
	@make -s all -C MLX42
	@echo $(G)Finished Compiling of [MLX42]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME_BONUS)]...$(X)
	@$(CC) $(CFLAGS) $(INCLUDES_BONUS) $(OBJECTS_BONUS) $(LIBS) -o $(NAME_BONUS)
	@echo $(G)Finished Compiling of [$(NAME_BONUS)]$(X)

bonus: $(NAME_BONUS)

clean_bonus:
	@make clean -C libft -s
	@echo $(R)Removed libft objects$(X)
	@make clean -C MLX42 -s
	@echo $(R)Removed MLX42 objects$(X)
	@$(RM) $(OBJECTS_BONUS)
	@echo $(R)Removed following objects: [$(OBJECTS_BONUS)]$(X)

fclean_bonus: clean_bonus
	@make fclean -C libft -s
	@echo $(R)Removed following executable: [libft.a]$(X)
	@make fclean -C MLX42 -s
	@echo $(R)Removed following executable: [MLX42.a]$(X)
	@$(RM) $(NAME_BONUS)
	@echo $(R)Removed following executable: [$(NAME_BONUS)]$(X)

re_bonus: fclean_bonus bonus

norma_bonus:
	@echo $(B)Checking Norminette...$(X)
	@norminette $(CFILES_BONUS) ./bonus/includes

.PHONY: all clean fclean re norma bonus clean_bonus fclean_bonus re_bonus norma_bonus
