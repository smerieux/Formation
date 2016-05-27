# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smerieux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 08:03:37 by smerieux          #+#    #+#              #
#    Updated: 2016/02/09 08:03:42 by smerieux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_LIB	=	ft_atof.c ft_atoh.c	ft_atoi.c ft_atoul.c ft_bzero.c	\
			ft_free_tab.c ft_isalnum.c ft_isalpha.c	ft_isascii.c \
			ft_isdigit.c ft_ishexa.c ft_isoctale.c ft_isprint.c	\
			ft_isspace.c ft_isupper.c ft_itoa.c	ft_itob.c ft_lstnew.c \
			ft_lstdelone.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memdel.c	ft_memmove.c ft_memset.c \
			ft_pow.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
			ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
			ft_putstr_fd.c ft_replace.c ft_strcat.c ft_strchr.c ft_strclr.c \
			ft_strcmp.c ft_strcpy.c	ft_strdel.c	ft_strdup.c	ft_strequ.c	\
			ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
			ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strnchr.c ft_strndup.c ft_strnequ.c ft_strnew.c \
			ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strsplit_space.c \
			ft_strstr.c ft_strsub.c	ft_strtrim.c ft_tabdup.c \
			ft_tablen.c ft_tolower.c ft_toupper.c ft_uitoa.c \
			get_next_line.c
OBJ_LIB	=	$(SRC_LIB:.c=.o)
CFLAGS 	= 	-Wall -Werror -Wextra -I./includes/ -I/usr/include
HEAD	=	includes/libft.h includes/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ_LIB) $(HEAD)
	@ar -rc $(NAME) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[1;32;40m\"$(NAME)\" created!!\033[0m"

%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $^

clean:
	@/bin/rm -f $(OBJ_LIB)
	@echo "\033[1;31;40mCleaning libft objects done!!\033[0m"

fclean:	clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;31;40mCleaning all done!!\033[0m"

re:	fclean all

.PHONY:	all re fclean clean
