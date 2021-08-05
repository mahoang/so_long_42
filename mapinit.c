/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:42:39 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/05 18:03:15 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	pixel_put(t_data mlx, t_map mapdata, int i, int j, int colour)
{
	int x;
	int y;
	int ts_x;
	int ts_y;

	x = 0;
	y = 0;
	ts_x = S_SCREEN_X / mapdata.xmax;
	ts_y = S_SCREEN_Y / mapdata.ymax;
	while (x < ts_x)
	{
		while (y < ts_y)
		{
			my_mlx_pixel_put(&mlx, x + ts_x * i, y + ts_y * j, colour);
			y++;
		}
		x++;
		y = 0;
	}
}


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
		printf("\n x value %zu\n", x);

			if (map[x][y] == CHAR_WALL)
				pixel_put(mlx,mapdata, x, y,WALL_COLOUR);
			/*if (map[x][y] == CHAR_EMPTY)
				pixel_put(mlx,mapdata,x, y, EMPTY_COLOUR);
			if (map[x][y] == CHAR_PC)
				pixel_put(mlx,mapdata,x, y, PC_COLOUR);
			if (map[x][y] == CHAR_COLLECT)
				pixel_put(mlx,mapdata,x, y, COLLECT_COLOUR);
			if (map[x][y] == CHAR_EXIT)
				pixel_put(mlx,mapdata,x, y, EXIT_COLOUR);*/
		x++;
		y = 0;
	}
	printf("\ntest E\n");

	return (1);
}
