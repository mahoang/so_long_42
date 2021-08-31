/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:47:02 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/31 18:26:08 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

/*
**check if map is rectangular
**if rectangular return 1
**if not return 0
*/
int check_rectangle(t_map *map_data,char **line)
{
	size_t i;
	int j;

	i = 1;
	j = 0;

	while (line[i][j])
		j++;
	map_data->xmax = j;
	//printf("col max%zu\n", map_data->xmax);
	j = 0;
	while (line[i] != NULL)
	{
		//printf("i %zu\n", i);
		//printf("strlen %zu\n", ft_strlen(line[i]));
		if(map_data->xmax != ft_strlen(line[i]))
			return (0);
		i++;
		//printf("--------------\n");
	}
	map_data->ymax = i;
	//printf("******************\n");
	return (1);
}

/*
**check if surrounded by walls
**return 1 if if it does
**return - if it's not
** in order West/South/East/North
*/
int check_walls(char **map, t_map *map_data )
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < map_data->ymax -1)
	{
		if (map[i][j] != CHAR_WALL)
			return (0);
		i++;
	}
	while (j < map_data->xmax -1)
	{
		if (map[i][j] != CHAR_WALL)
			return (0);
		j++;
	}
	while (i > 0)
	{
		if (map[i][j] != CHAR_WALL)
			return (0);
		i--;
	}
	while (j > 0)
	{
		if (map[i][j] != CHAR_WALL)
			return (0);
		j--;
	}
	return (1);
}

/*
**check collectibles
**return 1 and coordonate if present
**return - if not
** TODO voir pour le cas ou il y a plusieurs collectibles
*/
int check_collectible( t_map *map, char **line)
{
	int i;
	int j;


	i = 1;
	j = 1;
	while (line[i])
	{
		while (line[i][j])
		{
			if (line[i][j] == CHAR_COLLECT)
			{
				map->collectiblex++;
			}
			j++;
		}
		j = 1;
		i++;
	}
	if (map->collectiblex > 0)
		return (1);
	return (0);
}
/*
int check_multi_collectible( t_map *map, char **line)
{
	int i;
	int j;
	int x;
	int y;


	i = 0;
	j = 0;
	x = 0;
	y = 0;
	printf("\n-----\n");
	printf("%c coll", map->multicollx[0]);

	while (line[i])
	{
		while (line[i][j])
		{
			if (line[i][j] == 'C')
			{
				map->multicollx[x] = j;
				map->multicolly[y] = i;
				x++;
				y++;
				return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	printf("\n-----\n");
	return (0);
}
*/
/*
**check if exit exist
**return 1 and coordinate if do
**return 0 if not
*/
int check_exit(t_map *map,char **line)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (line[i])
	{
		while (line[i][j])
		{
			if (line[i][j] == CHAR_EXIT)
			{
				map->exitx = j;
				map->exity = i;
				return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}


/*
**check if player exist
**return 1 and coordinate if do
**return 0 if not
*/
int check_player(t_map *map,char **line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i][j])
		{
			if (line[i][j] == CHAR_PC)
			{
				map->playerx = j;
				map->playery = i;
				line[i][j] = CHAR_EMPTY;
				//printf("\nposition : [%zu, %zu]\n", map->playerx, map->playery);

				return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int testprint(char **map)
{
	int i = 0;
	int j = 0;

	while (map[i])
	{
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		//printf("adresse %p", map[i]);
		printf("\n");
		j = 0;
		i++;
	}
	printf("\n");
	//printf("adresse %p", map[i]);
	return (0);
}

t_map	init_struct()
{
	t_map map_data;
	map_data.ymax = 0;
	map_data.xmax = 0;
	map_data.collectiblex = 0;
	map_data.collectibley = 0;
	//map_data.multicollx = 0;
	//map_data.multicolly = 0;
	map_data.exitx = 0;
	map_data.exity = 0;
	map_data.playerx = 0;
	map_data.playery = 0;
	return (map_data);
}

int	ft_parsing(char *file, t_all *all)
{
	if (get_file(file, &all->map) == -1)
		return (-1);
	//testprint(all->map);
	//printf("\nmapdata ymax--%zu\n", all->map_data->xmax);
	if (check_rectangle(all->map_data, all->map) == 0)
		return (3);
	//printf("\nmapdata xmax--++%zu", all->map_data->xmax);
	//printf("\nmapdata ymax--++%zu", all->map_data->ymax);

	if (check_walls(all->map, all->map_data) == 0)
		return (4);
	if (check_collectible(all->map_data, all->map) == 0)
		return (5);
	if (check_exit(all->map_data, all->map) == 0)
		return (6);
	if (check_player(all->map_data, all->map) == 0)
		return (7);
	//printf("\ntest\n");
	return (1);
}
