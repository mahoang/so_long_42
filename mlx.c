/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:05 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/06 13:42:33 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int hook(int key, t_all *all)
{
	if (key == KEY_ESC)
	{
		exit(0);
	}
	/*if (key == KEY_Z || KEY_ARR_UP)
		move(KEY_ARR_UP, all);
	if (key == KEY_S || KEY_ARR_D)
		move(KEY_ARR_D);
	if (key == KEY_Q || KEY_ARR_L)
		move(KEY_ARR_L);
	if (key == KEY_D || KEY_ARR_R)
		move(KEY_ARR_R);*/
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
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	//mlx_key_hook(mlx_win, hook, &img);
	mlx_key_hook(mlx_win, hook, all); // t_all *all;
	mlx_loop(mlx);
}
