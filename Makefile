# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gofernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 16:45:07 by gofernan          #+#    #+#              #
#    Updated: 2018/04/30 16:44:41 by gofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
#NAME = miprintf
#FLAGS = -Wall -Wextra -Werror

#argorder
FLS = checkstr \
	  checkstr_argorder \
	  checkstr_flags \
	  checkstr_fwidth \
	  checkstr_precision \
	  checkstr_length_hh \
	  checkstr_length_h \
	  checkstr_length_ll \
	  checkstr_length_l \
	  checkstr_length_j \
	  checkstr_length_t \
	  checkstr_length_z \
	  checkstr_length_q \
	  conversion_specifiers \
	  sconv \
	  field_width \
	  field_width_num \
	  ft_printf \
	  initialize_struct \
	  precisionf \
	  lsconv \
	  utf8conv \
	  onebyteconv \
	  precisionfw \
	  diconv \
	  precisiondigits \
	  flag_space \
	  flag_plus \
	  flag_sharp \
	  uconv \
	  oconv \
	  xconv \
	  cconv \
	  lcconv \
	  percent \
	  pconv \
	  store_write \
	  checkstr_allargs \
	  store_arglist \
	  retr_arglist \
	  sel_arglist \
	  #main 

FTFLS = ft_bzero \
		ft_memset \
		ft_memmove \
		ft_strlen	\
		ft_strdup \
		ft_putchar \
		ft_strcpy \
		ft_putstr \
		ft_strncpy \
		ft_strcat \
		ft_strncat \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_memcpy \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_strncmp \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_memalloc \
		ft_memdel \
		ft_strnew \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strmap \
		ft_strmapi \
		ft_strequ \
		ft_strnequ \
		ft_strsub \
		ft_strjoin \
		ft_strtrim \
		ft_putendl \
		ft_putnbr \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_itoa \
		ft_atoi \
		ft_lstmap \
		ft_strsplit \
		ft_div_mod \
		ft_nlen \
		ft_wcslen \
		ft_ltoa \
		ft_lltoa \
		ft_imaxtoa \
		ft_uimaxtoa \
		ft_imaxtoa_base \
		ft_uimaxtoa_base \
		ft_strncpynp \

FTDIR = libft/
HEADER = includes/

CFLS = $(patsubst %, %.c, $(FLS))
OFLS = $(patsubst %, %.o, $(FLS))

CFTFLS = $(patsubst %, $(FTDIR)%.c, $(FTFLS))
OFTFLS = $(patsubst %, %.o, $(FTFLS))

OFTLSCURRENT = $(patsubst %, %.o, $(FTFLS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFLS) $(OFTFLS)
	ar rc $(NAME) $(OFLS) $(OFTFLS)
	#gcc $(FLAGS) $(OFTFLS) $(OFLS) -o $(NAME)

$(OFLS): $(CFLS) $(CFTFLS)
#$(OFLS):
	gcc -c -g -I$(HEADER) $(CFLS) $(CFTFLS)

clean:
	/bin/rm -f $(OFLS)
	/bin/rm -f $(OFTLSCURRENT)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all
