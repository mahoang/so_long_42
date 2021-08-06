/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:42:39 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/06 17:07:50 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	pixel_put(t_all *all, int i, int j, int colour)
{
	int	x;
	int	y;
	int	ts_x;
	int	ts_y;

	x = 0;
	y = 0;
	ts_x = S_SCREEN_X / all->map_data->xmax;
	ts_y = S_SCREEN_Y / all->map_data->ymax;
	while (x < ts_x)
	{
		while (y < ts_y)
		{
			my_mlx_pixel_put(all->mlx_data, x + ts_x * i, y + ts_y * j, colour);
			y++;
		}
		x++;
		y = 0;
	}
}

/*
**going thro the map and colouring them
	*/
int	init_tiles(t_all *all)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < all->map_data->xmax)
	{
		while (y < all->map_data->ymax)
		{
			if (all->map[y][x] == CHAR_WALL)
				pixel_put(all, x, y, WALL_COLOUR);
			if (all->map[y][x] == CHAR_EMPTY)
				pixel_put(all, x, y, EMPTY_COLOUR);
			if (all->map[y][x] == CHAR_PC)
				pixel_put(all, x, y, PC_COLOUR);
			if (all->map[y][x] == CHAR_COLLECT)
				pixel_put (all, x, y, COLLECT_COLOUR);
			if (all->map[y][x] == CHAR_EXIT)
				pixel_put(all, x, y, EXIT_COLOUR);
			y++;
		}
		x++;
		y = 0;
	}
	return (1);
}
