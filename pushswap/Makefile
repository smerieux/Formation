# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 18:07:05 by smerieux          #+#    #+#              #
#    Updated: 2013/12/28 19:04:44 by smerieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
export CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./libft/includes -I/usr/include
DFLAGS = -g3 -DD_ERROR_ON
LFLAGS = -L./libft -lft
NAME = push_swap
DEBUG = debug
SRC = push_swap.c push_rules.c rot_rules.c tools_sort1.c tools_sort2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) push_swap.h
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
