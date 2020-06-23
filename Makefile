# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/09 07:31:15 by nneronin          #+#    #+#              #
#    Updated: 2020/06/23 12:42:53 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = ./srcs/main.c\
	   ./srcs/color_gradient.c\
	   ./srcs/controls.c\
	   ./srcs/fractals.c\
	   ./srcs/threading.c\
	   ./srcs/select_fractal.c\
	   ./srcs/ui.c\
	   ./srcs/draw.c\
	   ./srcs/error_msg.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft/libft.a
ERROR_MSG = ./error_msg.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ./libft/
	@gcc -o $(NAME) $(SRCS) $(FLAGS) $(INCLUDES) -L./mlx/ -lmlx -pthread -framework OpenGL -framework AppKit
	@echo "$(NAME) was created."
clean:
	/bin/rm -f $(OBJS)
	make -C ./libft/ clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY: clean, all, re, fclean
