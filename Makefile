# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 10:30:52 by user42            #+#    #+#              #
#    Updated: 2021/07/29 11:35:39 by zephyrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_MLX	= ./mlx
SRCS		= $(wildcard *.c)
CC			= clang -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long



all:		 ${NAME}
${NAME} : ${CC} ${CFLAGS} -o ${SRCS}
clean:
fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
