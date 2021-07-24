# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 10:30:52 by user42            #+#    #+#              #
#    Updated: 2021/07/24 16:17:05 by zephyrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_MLX	= ./mlx
PATH_GNL	= ./GNL
CC			= gcc -g -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long



all:		 ${NAME}
clean:
fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
