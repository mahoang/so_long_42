/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:50:18 by user42            #+#    #+#             */
/*   Updated: 2021/08/04 16:11:32 by zephyrus         ###   ########.fr       */
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

/*
KEY
*/

# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_ARROW_TOP 65362
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_BOT 65364
# define KEY_ARROW_RIGHT 65363
/*
DEFINE
*/
# define WIN_NAME "so_long"
# define S_SCREEN_X 1080
# define S_SCREEN_Y 720

# define CHAR_WALL '1'
# define CHAR_EMPTY '0'
# define CHAR_PC 'P'
# define CHAR_COLLECT 'C'
# define CHAR_EXIT 'E'

# define WALL_COLOUR 0x002c5160
# define EMPTY_COLOUR 0x00c0bfbb
# define PC_COLOUR 0x00d45b61
# define COLLECT_COLOUR 0x00f0e4d2
# define EXIT_COLOUR 0xa12b8a

/*
STRUCTURE
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

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
int is_error(char *str);
int	ft_extension(char *c);
void		*ft_memmove(void *dest, const void *src, size_t len);
char		*str_join(char const *s1, char const *s2);
int			has_ret(char *str);
char		*get_save(char *save);
char		*get_line(char *str);
int			gnl(int fd, char **line);
int	ft_parsing(char *file, char ***map);
int	get_file(char *file, char ***map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void init_mlx();
int hook(int key);
#endif
