/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:47:02 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/04 16:13:58 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"

/*
**check if map is rectangular
**if rectangular return 1
**if not return 0
** TODO recuperer
*/
int check_rectangle(t_map *map_metadata,char **line)
{
	size_t i;
	int j;

	i = 1;
	j = 0;

	while (line[i][j])
		j++;
	map_metadata->xmax = j;
	//printf("col max%zu\n", map->col_max);
	j = 0;
	while (line[i] != NULL)
	{
		//printf("coucou\n");
		//printf("i %zu\n", i);
		//printf("strlen %zu\n", ft_strlen(line[i]));
		if(map_metadata->xmax != ft_strlen(line[i]))
			return (0);
		i++;
		//printf("--------------\n");
	}
	map_metadata->ymax = i;
	//printf("******************\n");
	return (1);
}

/*
**check if surrounded by walls
**return 1 if if it does
**return - if it's not
** in order West/South/East/North
*/
int check_walls(char **map, t_map *map_metadata )
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < map_metadata->ymax -1)
	{
		if (map[i][j] != CHAR_WALL)
			return (0);
		i++;
	}
	while (j < map_metadata->xmax -1)
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
				map->collectiblex = j;
				map->collectibley = i;
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
				return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	//printf("\n-------\n");
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
	printf("adresse %p", map[i]);
	return (0);
}
void	init_struct()
{
	t_map map_metadata;
	map_metadata.ymax = 0;
	map_metadata.xmax = 0;
	map_metadata.collectiblex = 0;
	map_metadata.collectibley = 0;
	//map_metadata.multicollx = 0;
	//map_metadata.multicolly = 0;
	map_metadata.exitx = 0;
	map_metadata.exity = 0;
	map_metadata.playerx = 0;
	map_metadata.playery = 0;
}
int	ft_parsing(char *file, char ***map)
{
	t_map map_metadata;
	init_struct();
	if (get_file(file, map) == -1)
		return (-1);
	//testprint(*map);
	if (check_rectangle(&map_metadata, *map) == 0)
		return (3);
	if (check_walls(*map, &map_metadata) == 0)
		return (4);
	if (check_collectible(&map_metadata, *map) == 0)
		return (5);
	if (check_exit(&map_metadata, *map) == 0)
		return (6);
	if (check_player(&map_metadata, *map) == 0)
		return (7);
	return (1);
}
