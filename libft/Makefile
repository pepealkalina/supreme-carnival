# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 10:08:21 by preina-g          #+#    #+#              #
#    Updated: 2023/11/09 14:15:57 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

NAME = libft.a

INCLUDE = libft.h

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c\
ft_strlcpy.c ft_strlcat.c ft_memmove.c ft_memset.c ft_strchr.c ft_strnstr.c ft_strrchr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 42-Get_next_line/get_next_line.c 42-Get_next_line/get_next_line_utils.c

OBJECTS = $(SRC:.c=.o)

BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(BONUSOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJECTS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS) $(NAME)

re:	fclean all
	

rebonus: fclean all
	
