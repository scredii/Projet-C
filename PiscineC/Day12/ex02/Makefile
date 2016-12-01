#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 14:51:43 by ddufour           #+#    #+#              #
#    Updated: 2016/03/03 00:49:13 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

EXEC = ft_tail

all: $(EXEC)
	$(CC) -c main.c ft_fonct.c
$(EXEC): main.o ft_fonct.o header.h
	$(CC) $^
	mv a.out $(EXEC)
clean:
	rm -rf main.o ft_fonct.o header.h.gch

fclean: clean
	rm -rf $(EXEC)

re: fclean all