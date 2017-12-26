#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 11:07:45 by jcoutare          #+#    #+#              #
#    Updated: 2017/12/26 17:02:51 by jcoutare         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = 	src/print.c \
		src/pos.c \
		src/algo2.c \
		src/algo.c \
		src/read.c \
		src/parse.c \
		src/tools.c \
		src/place.c
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
