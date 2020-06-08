# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:36:06 by tlernoul          #+#    #+#              #
#    Updated: 2018/01/07 00:07:19 by tlernoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_isdigit.c \
		ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memdel.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strdup.c \
		ft_striter.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strncat.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_strstr.c ft_strcmp.c ft_strcpy.c \
		ft_atoi.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_strequ.c ft_strjoin.c ft_strnequ.c ft_strsplit.c ft_strsub.c ft_strtrim.c \
		ft_strdel.c ft_strnew.c ft_strclr.c ft_strmapi.c ft_itoa.c ft_getndigits.c \
		ft_lstadd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
		ft_putlst.c ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c \
		ft_str_is_printable.c ft_str_is_uppercase.c ft_strcapitalize.c ft_strlowcase.c \
		ft_strupcase.c ft_lstsplit.c ft_strappend.c ft_strclen.c ft_strlenc.c ft_strclenc.c \
		ft_strrep.c get_next_line.c ft_countwords.c ft_retwords.c ft_itoabase.c \
		ft_hsl_to_rgb.c ft_hsv_to_rgb.c ft_strcmp_nocase.c

HEADER = libft.h
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	@printf "Compiling files..... $@                                   \r"
	@gcc -c -o $@ $^

$(NAME): $(OBJ)
	@printf "Functions archived. \033[32m✔\033[0m                      \n"
	@ar rc $(NAME) $(OBJ)
	@printf "Library created. \033[32m✔\033[0m                         \n"
	@ranlib $(NAME)
	@printf "Done.                                                     \n"

clean:
	@rm -f $(OBJ)
	@printf "Object Files cleaned. \033[32m✔\033[0m                    \n"

fclean: clean
	@rm -f $(NAME)
	@printf "Libft files purged. \033[32m✔\033[0m                      \n"

re: fclean all
