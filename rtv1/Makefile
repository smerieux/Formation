# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 18:07:05 by smerieux          #+#    #+#              #
#    Updated: 2016/01/08 12:45:23 by smerieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
export CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./libft/includes -I/usr/include -I./includes
DFLAGS = -g3 -DD_ERROR_ON
LFLAGS = -L./libft -lft
LFLAGS += -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL \
		-framework AppKit
NAME = rtv1
DEBUG = debug
SRC = 	tools/main.c tools/ft_raytracing.c tools/ft_find_inter.c \
		tools/ft_destroy_data.c	color/ft_find_color.c \
		color/ft_color_tools.c color/ft_calcul_lights.c \
		objects/ft_cone.c objects/ft_plane.c objects/ft_sphere.c \
		objects/ft_cylinder.c objects/ft_hyperboloid.c \
		parsing/ft_struct.c	parsing/ft_camera.c	parsing/ft_parsing.c \
		parsing/ft_parse.c parsing/ft_get_light.c \
		parsing/ft_check_float.c vector/ft_vec_ope.c \
		vector/ft_vec_tools.c vector/ft_vec_rotation.c
OBJ = $(SRC:.c=.o)
HEAD = includes/ft_rt.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEAD)
	@($(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS))
	@echo ""
	@echo "\033[1;32;40m\"$(NAME)\" created!!\033[0m"

$(DEBUG): $(LIBFT)
	@($(CC) $(CFLAGS) $(DFLAGS) $(SRC) -o $(DEBUG) $(LFLAGS))
	@echo "\033[1;32;40m\"$(DEBUG)\" created!!\033[0m"

$(LIBFT):
	@(cd  $(LIBFT_DIR) && $(MAKE))

%.o: %.c
	@echo -n .
	@($(CC) $(CFLAGS) -c $^ -o $@)

clean:
	@(rm -rf $(DEBUG).dSYM $(OBJ) $(DEBUG))
	@(cd  $(LIBFT_DIR) && $(MAKE) $@)
	@echo "\033[1;31;40mCleaning debug set done!!\033[0m"

fclean: clean
	@(rm -f $(NAME) $(OBJ))
	@(cd  $(LIBFT_DIR) && $(MAKE) $@)
	@echo "\033[1;31;40mCleaning all done!!\033[0m"

re: fclean all

.PHONY: clean, fclean
