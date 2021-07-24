/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:50:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/24 17:28:10 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

/*
LIBRARIES
*/
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "./mlx/mlx.h"
# include "./GNL/get_next_line.h"

/*
KEY
*/

/*
DEFINE
*/
#define BUFFER_SIZE 8
/*
STRUCTURE
*/

/*struct check map*/
typedef struct s_map
{
	int		lines;
	int		cor_lines;
	int		col_max;
}				t_map;

typedef struct s_coord
{
	float	x;
	float	y;
}				t_coord;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;
/*
FUNCTION
*/
size_t		ft_strlen(const char *s);
void		*ft_memmove(void *dest, const void *src, size_t len);
char		*str_join(char const *s1, char const *s2);
int			has_ret(char *str);
char		*get_save(char *save);
char		*get_line(char *str);
int			gnl(int fd, char **line);


#endif
