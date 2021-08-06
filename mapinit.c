/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:42:39 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/06 12:52:53 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	pixel_put(t_data mlx, t_map mapdata, int i, int j, int colour)
{
	int	x;
	int	y;
	int	ts_x;
	int	ts_y;

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

/*
**going thro the map and colouring them
	*/
int	init_tiles(char **map, t_map mapdata, t_data mlx)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < mapdata.xmax)
	{
		while (y < mapdata.ymax)
		{
			if (map[y][x] == CHAR_WALL)
				pixel_put(mlx, mapdata, x, y, WALL_COLOUR);
			if (map[y][x] == CHAR_EMPTY)
				pixel_put(mlx, mapdata, x, y, EMPTY_COLOUR);
			if (map[y][x] == CHAR_PC)
				pixel_put(mlx, mapdata, x, y, PC_COLOUR);
			if (map[y][x] == CHAR_COLLECT)
				pixel_put (mlx, mapdata, x, y, COLLECT_COLOUR);
			if (map[y][x] == CHAR_EXIT)
				pixel_put(mlx, mapdata, x, y, EXIT_COLOUR);
			y++;
		}
		x++;
		y = 0;
	}
	return (1);
}
