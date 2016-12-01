#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 14:51:43 by ddufour           #+#    #+#              #
#    Updated: 2016/03/14 16:17:50 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

EXEC = ft_cat

$(EXEC): main.o
	$(CC) $^
	mv a.out $(EXEC)
all: $(EXEC)
	$(CC) -c main.c
clean:
	rm -rf main.o

fclean: clean
	rm -rf $(EXEC)

re: fclean all