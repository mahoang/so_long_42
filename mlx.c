/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:05 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/24 11:23:07 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int hook(int key, t_all *all)
{
	//init_tiles(all);
	if (key == KEY_ESC)
	{
		exit(0);
	}
	if (key == (KEY_Z || key == KEY_ARR_UP))
		move(KEY_ARR_UP, all);
	if (key == KEY_S || key == KEY_ARR_D)
		move(KEY_ARR_D, all);
	if (key == KEY_Q || key == KEY_ARR_L)
		move(KEY_ARR_L, all);
	if (key == KEY_D || key == KEY_ARR_R)
		move(KEY_ARR_R, all);
	//mlx_put_image_to_window(mlx, mlx_win, all->mlx_data->img, 0, 0);
	return (key);
}

void init_mlx(t_all *all)
{
	void	*mlx;
	void	*mlx_win;
	t_data	mlx_data;

	all->mlx_data = &mlx_data;
	//printf("\n-123mapdata ymax%zu\n", all->map_data->ymax);
	//printf("\n-123mapdata xmax%zu\n", all->map_data->xmax);
	//printf("position : [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);

	mlx = mlx_init();

	mlx_win = mlx_new_window(mlx, S_SCREEN_X, S_SCREEN_Y, WIN_NAME);
	//printf("\ntest B\n");
	all->mlx_data->img = mlx_new_image(mlx, S_SCREEN_X, S_SCREEN_Y);
	//printf("\ntest C\n");
	all->mlx_data->addr = mlx_get_data_addr(all->mlx_data->img, &all->mlx_data->bpp, &all->mlx_data->line_len,
								&all->mlx_data->endian);
	printf("\ntest A\n");
	mlx_do_sync(mlx);
	mlx_key_hook(mlx_win, hook, all);
	printf("\ntest E\n");

	init_tiles(all);
	printf("\ntest F\n");

	mlx_put_image_to_window(mlx, mlx_win, all->mlx_data->img, 0, 0);
	//mlx_loop_hook(mlx,hook, all); #care not working
	//init_tiles(all);
	printf("\ntest D\n");

	mlx_loop(mlx);
}

//faire une fonction qui va dessiner 'draw'? le mettre dans mlx_loop_hook
//mettre mlx_put_image_to_window dans 'draw'?
