# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 18:07:05 by smerieux          #+#    #+#              #
#    Updated: 2014/01/19 17:11:46 by smerieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
export CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./libft/includes -I/usr/include
DFLAGS = -g3 -DD_ERROR_ON
LFLAGS = -L./libft -lft
LFLAGS += -L/usr/X11/lib -lmlx -lXext -lX11
NAME = wolf3d
DEBUG = debug
SRC = main.c get_next_line.c ft_initialisation.c ft_loop_hook.c \
	  ft_move_calculate.c ft_calcul.c ft_check_open_close.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) get_next_line.h wolf3d.h
	@($(CC) $(CFLAGS) -o $@ $(OBJ) $(LFLAGS))
	@echo "\033[1;32;40m\"$(NAME)\" created!!\033[0m"

$(DEBUG): $(LIBFT)
	@($(CC) $(CFLAGS) $(DFLAGS) $(SRC) -o $(DEBUG) $(LFLAGS))
	@echo "\033[1;32;40m\"$(DEBUG)\" created!!\033[0m"

$(LIBFT):
	@(cd  $(LIBFT_DIR) && $(MAKE))

%.o: %.c
	@($(CC) $(CFLAGS) -c $^)

clean:
	@(rm -rf $(DEBUG).dSYM $(OBJ) $(DEBUG))
	@(cd  $(LIBFT_DIR) && $(MAKE) $@)
	@echo "\033[1;31;40mCleaning debeug set done!!\033[0m"

fclean: clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@(rm -f $(NAME) $(OBJ))
	@echo "\033[1;31;40mCleaning all done!!\033[0m"

re: fclean all

.PHONY: clean, fclean
