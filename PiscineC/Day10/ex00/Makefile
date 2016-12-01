#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 18:13:01 by ddufour           #+#    #+#              #
#    Updated: 2015/12/15 18:25:05 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c  srcs/ft_swap.c

OBJ = $(SRC:.c=.o)

EXEC = libft.a

all: $(EXEC)

$(EXEC):  $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(EXEC)

re: fclean all