# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 10:30:52 by user42            #+#    #+#              #
#    Updated: 2021/07/30 12:36:57 by zephyrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_MLX	= ./mlx
SRCS		= check_map.c main.c\
				
CC			= clang -fsanitize=address -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
OBJS	= ${SRCS:.c=.o}

%.o: %.c
	$(CC) ${CFLAGS} -I/usr/include ${PATH_MLX} -O3 -c $< -o $@

all:		 ${NAME}
${NAME} : ${OBJ}
		${CC} ${CFLAGS} -o ${SRCS}
clean:
fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
#$(NAME): $(OBJ)
#	$(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
