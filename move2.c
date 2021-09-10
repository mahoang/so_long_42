/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:24:51 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/10 15:24:24 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_valid(int key, t_all *all)
{
	int	t_x;
	int	t_y;

	t_x = all->map_data->playerx;
	t_y = all->map_data->playery;
	if (key == KEY_ARR_UP)
		t_y--;
	else if (key == KEY_ARR_D)
		t_y++;
	else if (key == KEY_ARR_L)
		t_x--;
	else if (key == KEY_ARR_R)
		t_x++;
	if (all->map[t_y][t_x] == '1')
		return (0);
	return (1);
}

void	move(int key, t_all *all)
{
	if (is_valid(key, all) == 1)
	{
		if (key == KEY_ARR_UP)
			all->map_data->playery--;
		else if (key == KEY_ARR_D)
			all->map_data->playery++;
		else if (key == KEY_ARR_L)
			all->map_data->playerx--;
		else if (key == KEY_ARR_R)
			all->map_data->playerx++;
		movecount(key, all);
		printf("move counter is %i\n", all->countm);
		if (all->map[all->map_data->playery][all->map_data->playerx] == 'C')
		{
			all->map_data->collectiblex--;
			all->map[all->map_data->playery][all->map_data->playerx] = '0';
		}
		if ((all->map[all->map_data->playery][all->map_data->playerx] == 'E')
		&& all->map_data->collectiblex == 0)
		{
			printf("Gratz you finished it in %i\n", all->countm);
			exit_hook(all);
		}
	}
}
