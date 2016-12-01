#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/14 11:43:28 by ddufour           #+#    #+#              #
#    Updated: 2016/06/16 19:23:07 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

RM = rm -f

LIB = -I ./libft -L ./libft/ -lft

HEADER = -I ./include

CC = gcc -Wall -Werror -Wextra -I ./include

SRCS = srcs/main.c \
	   srcs/ft_resolve.c \
	   srcs/ft_creat_map.c \
	   srcs/fonct.c \
	   srcs/ft_push_left.c \
	   srcs/map_check.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) -o $(NAME) $(OBJS) $(LIB) $(HEADER)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
