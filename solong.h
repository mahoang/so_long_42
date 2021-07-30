/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:50:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/29 16:40:23 by zephyrus         ###   ########.fr       */
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
/*
STRUCTURE
*/

/*struct check map*/
typedef struct s_map
{
	size_t		ymax;//lines
	size_t		xmax;//col_max
	int		collectiblex;
	int		collectibley;
	char		*multicollx;
	char		*multicolly;
	int		exitx;
	int		exity;
	int		playerx;
	int		playery;
}				t_map;

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
int	ft_parsing(char *file, char ***map);
int is_error(char *str);
int	get_file(char *file, char ***map);

#endif
