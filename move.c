/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:54:41 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/07 14:21:25 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

/*
**Recuperer position du character et le deplacer
**recuperer struct + arrow key
**ecrire sur le terminal si deplacement sur case
**soit vide/recuperable/exit
**recuperer compteur de lootable
**
*/
char movetotarget(int key, t_all *all)
{
	// modifier le tableau en fonction du mvt
	// redessiner la nouvelle img
	// put_img_to_window
	if ((key == KEY_ARR_UP && all->map_data->playery - 1 < 0)
		|| (key == KEY_ARR_D && all->map_data->playery + 1 > all->map_data->ymax - 1)
		|| (key == KEY_ARR_L && all->map_data->playerx - 1 < 0)
		|| (key == KEY_ARR_R && all->map_data->playerx + 1 > all->map_data->xmax - 1))
		return (NULL);
	if (key == KEY_ARR_UP)
		return (all->map[all->map_data->playery -1][all->map_data->playerx]);
	else if (key == KEY_ARR_D)
		return (all->map[all->map_data->playery +1][all->map_data->playerx]);
	else if (key == KEY_ARR_L)
		return (all->map[all->map_data->playerx][all->map_data->playery - 1]);
	else if (key == KEY_ARR_R)
		return (all->map[all->map_data->playerx][all->map_data->playery + 1]);
	return (NULL);
}

void	effectivemove(int key, t_all *all)
{
	if (all->type == CHAR_EMPTY)
	{
		if (key == KEY_ARR_UP)
			all->map_data->playery -=1;
		else if (key == KEY_ARR_D)
			all->map_data->playery +=1;
		else if (key == KEY_ARR_L)
			all->map_data->playerx -=1;
		else if (key == KEY_ARR_R)
			all->map_data->playerx -=1;
		printf("position : [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);

	}
}
void	move(int key, t_all *all)
{
	//printf("position : [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);

	all->type = movetotarget(key, all);
	if (all->type == NULL)
		return;
	printf("\nmovetotype %c\n", all->type);
	effectivemove(key, all);
}
