#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 17:05:44 by ddufour           #+#    #+#              #
#    Updated: 2016/11/20 14:14:39 by ddufour          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

RM = rm -f

CCF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

SRCS =	srcs/main.c \
		srcs/fractol.c \
		srcs/utils.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@make -s -C libs/minilibx_macos
	@echo "Minilibx Compiled"
	@$(CCF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "Fract'ol Compiled"

all : $(NAME)

#%.o: %.c
#	@$(CCF) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@make clean -s -C libs/minilibx_macos
	@echo ".o Minilibx delete"
	@$(RM) $(OBJ)
	@echo ".o Fract'ol delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) libs/minilibx_macos/libmlx.a
	@echo "libmlx.a delete"
	@$(RM) $(NAME)
	@echo "fractol delete"

re : fclean all