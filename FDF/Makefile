#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 17:05:44 by ddufour           #+#    #+#              #
#    Updated: 2016/10/31 11:05:37 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

RM = rm -f

CCF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

SRCS =	srcs/bresenham.c \
		srcs/creat_lst.c \
		srcs/main.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@make -s -C libs/minilibx_macos
	$(CCF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^

all : $(NAME)

clean :
	make clean -C libs/libft
	make clean -C libs/minilibx_macos
	$(RM) $(OBJ)

fclean : clean
	$(RM) libs/libft/libft.a
	$(RM) libs/minilibx_macos/libmlx.a
	$(RM) $(NAME)

re : fclean all