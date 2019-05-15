# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 21:08:02 by flevesqu          #+#    #+#              #
#    Updated: 2019/01/12 15:32:44 by flevesqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes/
SRC = bitwises.c\
	  ft_atoi.c\
	  ft_rev_bytes.c\
	  ft_clamp.c\
	  ft_bzero.c\
	  ft_atoi_base.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_isupper.c\
	  ft_isspace.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_free_2d.c\
	  ft_getenv.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_splitwhitespaces.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_dlstadd.c\
	  ft_dlstdel.c\
	  ft_dlstdelone.c\
	  ft_dlstiter.c\
	  ft_dlstmap.c\
	  ft_dlstnew.c\
	  ft_dlstlast.c\
	  ft_dlstgetn.c\
	  ft_dlstswap.c\
	  ft_dlstlast.c\
	  ft_dlstgetn.c\
	  ft_strndup.c\
	  ft_dlstaddn.c\
	  get_next_line.c\
	  ft_printf.c\
	  ft_strchar.c\
	  ft_strscat.c\
	  ft_lstnew.c\
	  ft_new_heuristic.c\
	  ft_printf/conv_char.c\
	  ft_printf/conv_nb1.c\
	  ft_printf/conv_nb2.c\
	  ft_printf/conv_str.c\
	  ft_printf/conversion.c\
	  ft_printf/flags.c\
	  ft_string/ft_string_new.c\
	  ft_string/ft_string_offset.c\
	  ft_string/ft_string_from_chr.c\
	  ft_string/ft_string_from_rchr.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
