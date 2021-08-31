/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:54:41 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/31 19:32:28 by zephyrus         ###   ########.fr       */
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
char *movetotarget(int key, t_all *all)
{

	if ((key == KEY_ARR_UP && all->map_data->playery - 1 < 0)
		|| (key == KEY_ARR_D && all->map_data->playerx + 1 > all->map_data->ymax - 1)
		|| (key == KEY_ARR_L && all->map_data->playerx - 1 < 0)
		|| (key == KEY_ARR_R && all->map_data->playery + 1 > all->map_data->xmax - 1))
		{
			printf("\njepue\n");
			return(NULL);
		}
	//printf("player value %c\n", all->map[all->map_data->playery][all->map_data->playerx]);
	if (key == KEY_ARR_UP)
	{
		printf("\nupkey\n");
		return (&all->map[all->map_data->playery -1][all->map_data->playerx]);

		//return (*all->map[all->map_data->playery -1]);
	}
	else if (key == KEY_ARR_D)
	{
		//printf("\ndownkey\n");
		return (&all->map[all->map_data->playery +1][all->map_data->playerx]);
	}
	else if (key == KEY_ARR_L)
	{
		//printf("\nleftkey\n");
		return (&all->map[all->map_data->playerx][all->map_data->playery - 1]);
	}
	else if (key == KEY_ARR_R)
		return (&all->map[all->map_data->playerx][all->map_data->playery + 1]);
	return (NULL);
}
/*
** issue je redefinie pas la place ou j'etais du coup le type reste 1
*/
void	effectivemove(int key, t_all *all)
{
	//if (all->type == '0')
	//{
		if (key == KEY_ARR_UP)
		{
			printf("upmerde\n");
			all->map_data->playery -= 1;
		}
		else if (key == KEY_ARR_D)
			all->map_data->playery +=1;
		else if (key == KEY_ARR_L)
			all->map_data->playerx -=1;
		else if (key == KEY_ARR_R)
			all->map_data->playerx +=1;
	//}
	printf("\nposition : [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);
	printf("test je sais pas ce que je printtamere %s\n", all->map[all->map_data->playery]);
	printf("l'autre %s\n", all->map[all->map_data->playerx]);
	printf("lesdeux? %c\n", all->map[all->map_data->playery][all->map_data->playerx]);


	all->map[all->map_data->playery][all->map_data->playerx] = '0';

}
void	move(int key, t_all *all)
{
	printf("\nposition pre deplacement: [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);
	all->type = *movetotarget(key, all);
	printf("all->type %c\n", all->type);
	//if (all->type == 0)
	//	return;
	 if (all->type == '1')
	{
		printf("\nmur\n");
		return;
	}
	else if (all->type == 'P')
		printf("tarace");
	else if (all->type == 'C')
	{
		//printf("testcoll");
		all->map_data->collectiblex--;
		all->type = CHAR_EMPTY;
		printf("nb collectible %i\n", all->map_data->collectiblex);
		//all->map[all->map_data->playerx][all->map_data->playery] = '0';
	}
	//printf("\nmovetotype %c\n", type);
	testprint(all->map);

	effectivemove(key, all);
	printf("\nposition post deplacement: [%zu, %zu]\n", all->map_data->playerx, all->map_data->playery);
	printf("\ntype post deplacement %c\n", all->type);

}

