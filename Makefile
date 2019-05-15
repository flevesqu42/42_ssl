# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 00:33:10 by flevesqu          #+#    #+#              #
#    Updated: 2019/01/25 09:12:29 by flevesqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:$(SRC_DIR)=$(OBJ_DIR):.c=.o)

NAME = ft_ssl

LIB = libft

FILES =	main.c\
		run_ssl.c\
		init_hash_infos.c\
		parsing.c\
		parse_options.c\
		hash_files.c\
		sum_string.c\
		sum_file.c\
		sum_standard_input.c\
		display.c\
		error.c\
		blocks/get_blocks_from_fd.c\
		blocks/get_blocks_from_string.c\
		blocks/new_block.c\
		blocks/display_blocks.c\
		blocks/free_blocks.c\
		blocks/reverse_blocks.c\
		blocks/save_memory_in_blocks.c\
		errors/usage.c\
		errors/read_failed.c\
		errors/open_file.c\
		errors/malloc_failed.c\
		errors/invalid_command.c\
		errors/invalid_option.c\
		errors/no_argument_option.c\
		hashs/md5/md5.c\
		hashs/md5/init.c\
		hashs/sha256/sha256.c\
		hashs/sha256/init.c\
		hashs/sha512/sha512.c\
		hashs/sha512/init.c\

HASHS =	md5\
		sha256\
		sha512\

CC = clang

WFLAGS = -Wall -Werror -Wextra

ifdef DEBUG
	WFLAGS += -DDEBUGFLAG
endif

LFLAGS = -L $(LIB)/ -lft

LIB_INCLUDES = ./$(LIB)/includes/

SRC_INCLUDES = ./includes/

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

HEADERS =	$(SRC_INCLUDES)$(NAME).h\
			$(SRC_INCLUDES)error.h

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)errors
	mkdir -p $(OBJ_DIR)blocks
	mkdir -p $(OBJ_DIR)hashs
	mkdir -p $(addprefix $(OBJ_DIR)/hashs/,$(HASHS))

$(LIB) :
	make -C $(LIB)

obj/%.o: src/%.c $(HEADERS)
	$(CC) -c $(WFLAGS) -I $(LIB_INCLUDES) -I $(SRC_INCLUDES) $< -o $@

$(NAME) : $(OBJ) $(HEADERS)
	make -C $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) $(LFLAGS)

clean : lclean
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

lclean :
	make -C $(LIB)/ clean

fclean : lfclean clean
	rm -f $(NAME)

lfclean :
	make -C $(LIB)/ fclean

re : fclean all

lre :
	make -C $(LIB)/ re

.PHONY: all clean fclean re lclean lfclean lre
