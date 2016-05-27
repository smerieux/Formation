# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 13:30:38 by smerieux          #+#    #+#              #
#    Updated: 2013/12/16 12:28:40 by smerieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
	  ft_memset.c ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strdup.c\
	  ft_strlen.c ft_strncat.c ft_strncmp.c ft_itoa.c ft_strncpy.c\
	  ft_strlcat.c ft_strjoin.c ft_strnew.c ft_strmap.c ft_strmapi.c\
	  ft_strchr.c ft_strrchr.c ft_strnchr.c ft_strstr.c ft_strnstr.c \
	  ft_strsub.c ft_strtrim.c ft_strsplit.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strequ.c\
	  ft_strnequ.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	  ft_memccpy.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
	  ft_putnbr.c ft_putstr.c ft_putstr_fd.c ft_strdel.c ft_strclr.c\
	  ft_striter.c ft_striteri.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	  ft_replace.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	@(ar rc $(NAME) $(OBJ))
	@(ranlib $(NAME))
	@echo "\033[1;32;40m\"$(NAME)\" created!!\033[0m"

%.o: %.c
	@($(CC) $(CFLAGS) -c $^)

clean:
	@(rm -f $(OBJ))
	@echo "\033[1;31;40mCleaning objects done...\033[0m"

fclean: clean
	@(rm -f $(NAME))

re: fclean all
