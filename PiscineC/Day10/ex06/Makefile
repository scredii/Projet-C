#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 18:41:01 by ddufour           #+#    #+#              #
#    Updated: 2015/12/16 01:02:40 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CC = gcc

EXEC = do-op

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ header.h
	mv a.out $(EXEC)
 clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
