#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 11:07:45 by jcoutare          #+#    #+#              #
#    Updated: 2017/10/10 14:47:34 by jcoutare         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = 	src/read.c \
		src/get_next_line.c \
		src/parse.c \
		src/tools.c
NAME = jcoutare.filler

CC = clang

CFLAGS = -Werror -Wall -Wextra -Iincludes

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(CC) -o $(NAME) -Llibft -lft $(OBJ)

clean:
		make clean -C libft/
		rm -f $(OBJ)

fclean:
		make fclean -C libft/
		rm -f $(OBJ)
		rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
