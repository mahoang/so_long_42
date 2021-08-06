/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:59 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/06 12:31:38 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_extension(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[i - 4] == '.' && c[i - 3 == 'b'] && c[i - 2] == 'e' && c[i - 1] == 'r')
		return (0);
	return (1);
}

int is_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(-1);
}


/*
int init_tiles(char **map, t_map mapdata, t_data mlx)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	printf("\n-mapdata xmax%zu\n", mapdata.xmax);
	printf("\n-mapdata ymax%zu\n", mapdata.ymax);
	while (x < mapdata.xmax)
	{
		while (y < mapdata.ymax)
		{
			if (map[x][y] == CHAR_WALL)
				pixel_put(mlx,mapdata, x, y,WALL_COLOUR);
			if (map[x][y] == CHAR_EMPTY)
				pixel_put(mlx,mapdata,x, y, EMPTY_COLOUR);
			if (map[x][y] == CHAR_PC)
				pixel_put(mlx,mapdata,x, y, PC_COLOUR);
			if (map[x][y] == CHAR_COLLECT)
				pixel_put(mlx,mapdata,x, y, COLLECT_COLOUR);
			if (map[x][y] == CHAR_EXIT)
				pixel_put(mlx,mapdata,x, y, EXIT_COLOUR);
			y++;
			printf("\n y value %zu\n", y);
		}
		x++;
		printf("\n x value %zu\n", x);

		y = 0;
	}
	printf("\ntestE\n");

	return (1);
}



*/


/*


int init_tiles(char **map, t_map mapdata, t_data mlx)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	printf("\n-mapdata xmax%zu\n", mapdata.xmax);
	printf("\n-mapdata ymax%zu\n", mapdata.ymax);
	//if (map[4][10] == CHAR_WALL)
	//	pixel_put(mlx,mapdata, 10, 4,WALL_COLOUR);
	while (x < mapdata.xmax)
	{
			//printf("\n x value %zu\n", x);
			if (map[y][x] == CHAR_WALL)
				printf("\n x value %zu\n", x);
				pixel_put(mlx,mapdata, x, y,WALL_COLOUR);
			/*if (map[x][y] == CHAR_EMPTY)
				pixel_put(mlx,mapdata,x, y, EMPTY_COLOUR);
			if (map[x][y] == CHAR_PC)
				pixel_put(mlx,mapdata,x, y, PC_COLOUR);
			if (map[x][y] == CHAR_COLLECT)
				pixel_put(mlx,mapdata,x, y, COLLECT_COLOUR);
			if (map[x][y] == CHAR_EXIT)
				pixel_put(mlx,mapdata,x, y, EXIT_COLOUR);
		x++;
	}
	printf("\ntest E\n");

	return (1);
}
*/
