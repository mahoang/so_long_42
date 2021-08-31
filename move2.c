/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:24:51 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/31 21:18:44 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_valid(int key, t_all *all)
{
	int t_x;
	int t_y;
	t_x = all->map_data->playerx;
	t_y = all->map_data->playery;
	/*printf("test je sais pas ce que je printtamere %s\n", all->map[t_x]);
	printf("l'autre %s\n", all->map[t_y]);
	printf("lesdeux? %c\n", all->map[t_x][t_y]);

	*/
	printf("ymax %zu\n", all->map_data->ymax);
	printf("xmax %zu\n", all->map_data->xmax);
	printf("y %zu\n", all->map_data->playery);
	printf("\nposition : [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);
	if (key == KEY_ARR_UP)
		t_y -=1;
	else if (key == KEY_ARR_D && (t_y + 2 < (int)all->map_data->ymax - 2))
		t_y +=1;
	else if (key == KEY_ARR_L)
		t_x -=1;
	else if (key == KEY_ARR_R)
		t_x +=1;
	printf("ty et tx %c\n", all->map[t_y][t_x]);
	if (all->map[t_y][t_x] == '1')
		return (0);
	return(1);
}

void	move(int key, t_all *all)
{
		if (key == KEY_ARR_UP && is_valid(key, all))
			all->map_data->playery -= 1;
		else if (key == KEY_ARR_D && is_valid(key, all))
			all->map_data->playery +=1;
		else if (key == KEY_ARR_L && is_valid(key, all))
			all->map_data->playerx -=1;
		else if (key == KEY_ARR_R && is_valid(key, all))
			all->map_data->playerx +=1;
		if (all->map[all->map_data->playery][all->map_data->playerx] == 'C')
		{
			all->map_data->collectiblex--;
			all->map[all->map_data->playery][all->map_data->playerx] = '0';
		}

}
