#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/15 18:41:01 by ddufour           #+#    #+#              #
#    Updated: 2016/03/16 15:46:04 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC =	firstcaract.c\
		ft_convert_base.c\
		ft_fonct.c\
		ft_hexflag.c\
		ft_hexnoflag.c\
		ft_itoa.c\
		ft_print.c\
		main.c

OBJ = $(SRC:.c=.o)

CC = gcc -Werror -Wextra -Wall

EXEC = ft_hexdump

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

all: $(EXEC)

 clean:
	rm -rf $(OBJ) header.h.gch

fclean: clean
	rm -rf $(EXEC)

re: fclean all

