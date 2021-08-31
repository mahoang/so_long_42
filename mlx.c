/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:05 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/31 22:46:05 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int		exit_hook(void)
{
	exit(0);
	return (0);
}

int	main_loop(void *param)
{
	t_all	*all;

	all = param;
	init_tiles(all);
	init_chara(all);
	mlx_put_image_to_window(all->win->mlx, all->win->mlx_win, all->mlx_data->img, 0, 0);
	return (1);
}
int movecount(int key, t_all *all)
{

	if ((key == KEY_Z || key == KEY_ARR_UP)
	|| (key == KEY_S || key == KEY_ARR_D)
	|| (key == KEY_Q || key == KEY_ARR_L)
	|| (key == KEY_D || key == KEY_ARR_R))
		all->countM++;
	return (all->countM);
}

int hook(int key, t_all *all)
{
	t_all *info;
	info = all;

	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_Z || key == KEY_ARR_UP)
		move(KEY_ARR_UP, all);
	if (key == KEY_S || key == KEY_ARR_D)
		move(KEY_ARR_D, all);
	if (key == KEY_Q || key == KEY_ARR_L)
		move(KEY_ARR_L, all);
	if (key == KEY_D || key == KEY_ARR_R)
		move(KEY_ARR_R, all);
	//movecount(key, all);
	//printf("move counter is %i\n", all->countM);
	return (key);
}

void init_mlx(t_all *all)
{
	t_data	mlx_data;
	t_win	win;

	all->win = &win;
	all->mlx_data = &mlx_data;
	all->win->mlx = mlx_init();
	all->win->mlx_win = mlx_new_window(all->win->mlx, S_SCREEN_X, S_SCREEN_Y, WIN_NAME);
	all->mlx_data->img = mlx_new_image(all->win->mlx, S_SCREEN_X, S_SCREEN_Y);
	all->mlx_data->addr = mlx_get_data_addr(all->mlx_data->img, &all->mlx_data->bpp,
	&all->mlx_data->line_len,&all->mlx_data->endian);
	mlx_put_image_to_window(all->win->mlx, all->win->mlx_win, all->mlx_data->img, 0, 0);
	mlx_hook(all->win->mlx_win, 33, 1L << 17, exit_hook, all);
	mlx_hook(all->win->mlx_win, 2, 1L << 0, hook, all);
	mlx_loop_hook(all->win->mlx, main_loop, all); //utiliser
	mlx_loop(all->win->mlx);
}

