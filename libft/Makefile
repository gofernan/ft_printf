# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gofernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 19:11:35 by gofernan          #+#    #+#              #
#    Updated: 2017/12/07 05:42:12 by gofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all fclean clean re

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

OPTION = -c

FILES = ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_putchar.c \
		ft_strcpy.c \
		ft_putstr.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_itoa.c \
		ft_atoi.c \
		ft_lstmap.c \
		ft_strsplit.c\
		ft_div_mod.c

OES = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OES)
	ar rc $(NAME)  $(OES)

%.o: %.c
	@gcc $(FLAGS) -c $<
clean:
	/bin/rm -f $(OES)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
