/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:05 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/05 17:38:01 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int hook(int key)
{
	if (key ==KEY_ESC)
	{
		exit(0);
	}
	return (key);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void init_mlx(char ***map, t_map *map_data, t_data *img)
{
	void	*mlx;
	void	*mlx_win;

	//printf("\n-mapdata ymax%zu", map_data->ymax);
	//printf("\n-mapdata xmax%zu", map_data->xmax);
	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, S_SCREEN_X, S_SCREEN_Y, WIN_NAME);
	img->img = mlx_new_image(mlx, S_SCREEN_X, S_SCREEN_Y);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
								&img->endian);
	init_tiles(*map, *map_data, *img);
	/*int i = 0;
	int j = 0;
	while (i < 100)
	{
		while (j < 100)
		{
			my_mlx_pixel_put(&img, i, j, 0x002c5160);
			j++;
		}
		i++;
		j=0;
	}*/
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_key_hook(mlx_win, hook, &img);
	mlx_loop(mlx);
}
