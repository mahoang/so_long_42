/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:50:18 by user42            #+#    #+#             */
/*   Updated: 2021/09/04 14:52:02 by zephyrus         ###   ########.fr       */
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
//# define KEY_ARR_UP 126
# define KEY_ARR_UP 65362
# define KEY_ARR_L 65361
# define KEY_ARR_D 65364
//# define KEY_ARR_D 125
# define KEY_ARR_R 65363
/*
DEFINE
*/
# define WIN_NAME "so_long"
# define SSX 1080
# define SSY 720

# define CHAR_WALL '1'
# define CHAR_EMPTY '0'
# define CHAR_PC 'P'
# define CHAR_COLLECT 'C'
# define CHAR_EXIT 'E'

# define WALL_COLOUR 0x002c5160
# define EMPTY_COLOUR 0x00c0bfbb
# define PC_COLOUR 0x00d45b61
# define COLLECT_COLOUR 0xa12b8fa
# define EXIT_COLOUR 0xa12b8a

/*
STRUCTURE
*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}		t_win;

/*struct check map*/
typedef struct s_map
{
	size_t		ymax;
	size_t		xmax;
	int			collectiblex;
	int			collectibley;
	char		*multicollx;
	char		*multicolly;
	int			exitx;
	int			exity;
	size_t		playerx;
	size_t		playery;
}				t_map;

typedef struct s_all
{
	t_map	*map_data;
	t_data	*mlx_dt;
	t_win	*win;
	char	**map;
	char	type;
	int		countM;
}			t_all;

/*
FUNCTION
*/
size_t		ft_strlen(const char *s);
t_map		init_struct(void);
int			is_error(char *str, t_all *all);
int			is_error_gnl(char *str);
int			ft_extension(char *c);
void		*ft_memmove(void *dest, const void *src, size_t len);
char		*str_join(char const *s1, char const *s2);
int			has_ret(char *str);
char		*get_save(char *save);
char		*get_line(char *str);
int			gnl(int fd, char **line);
int			ft_parsing(char *file, t_all *all);
int			get_file(char *file, char ***map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init_mlx(t_all *all);
int			hook(int key, t_all *all);
int			init_tiles(t_all *all);
int			init_chara(t_all *all);
void		move(int key, t_all *all);
int			movecount(int key, t_all *all);
int			check_rectangle(t_map *map_data, char **line);
int			check_walls(char **map, t_map *map_data, unsigned int i,
				unsigned int j);
int			check_collectible( t_map *map, char **line);
int			check_exit(t_map *map, char **line);
int			check_player(t_map *map, char **line);
int			check_chara(char **map);
int			testprint(char **map);
void		free_tab(char **map);

#endif
