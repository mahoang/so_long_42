# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 10:30:52 by user42            #+#    #+#              #
#    Updated: 2021/07/10 10:49:51 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_MLX	= ./mlx
CC			= gcc -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long



all:		 ${NAME}
clean
fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
