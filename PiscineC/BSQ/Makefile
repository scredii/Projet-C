#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/23 00:02:19 by ddufour           #+#    #+#              #
#    Updated: 2016/05/24 14:49:41 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq

SRC =	src/main.c\
		src/valid_map.c\
		src/valid_map2.c\
		src/map_resolve.c\
		src/fonct.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all