# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 13:30:38 by smerieux          #+#    #+#              #
#    Updated: 2015/05/28 17:16:07 by smerieux         ###   ########.fr        #
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
	  ft_replace.c ft_atof.c ft_dtoa.c ft_strndup.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I./
LFLAGS = -L./ -lft
CC = gcc
EXEC = test

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^

$(EXEC): all
	$(CC) $(CFLAGS) -o $@ main.c $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

