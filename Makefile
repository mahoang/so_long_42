# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 14:50:31 by zephyrus          #+#    #+#              #
#    Updated: 2021/09/01 00:57:03 by zephyrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = solong.h
SRC = check_map.c get_file.c utils.c mlx.c mapinit.c main.c move2.c
LIB = -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd
INC = -I . -I ./mlx -I ./includes
OPTION = -L ./mlx
OBJ = $(SRC:.c=.o)

CC = clang
FLAGS = -Wall -Wextra -o3 -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER) -I/mlx

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(LIB) $(INC) $(OPTION) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean :	clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all
