#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 14:51:43 by ddufour           #+#    #+#              #
#    Updated: 2016/02/16 15:05:26 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

EXEC = ft_display_file

all: $(EXEC)
	$(CC) -c main.c
$(EXEC): main.o
	$(CC) $^
	mv a.out $(EXEC)
clean:
	rm -rf main.o

fclean: clean
	rm -rf $(EXEC)

re: fclean all