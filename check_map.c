/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:47:02 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/01 00:54:43 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
**check if map is rectangular
**if rectangular return 1
**if not return 0
*/
int	check_rectangle(t_map *map_data, char **line)
{
	size_t	i;
	int		j;

	i = 1;
	j = 0;
	while (line[i][j])
		j++;
	map_data->xmax = j;
	j = 0;
	while (line[i] != NULL)
	{
		if (map_data->xmax != ft_strlen(line[i]))
			return (0);
		i++;
	}
	map_data->ymax = i;
	return (1);
}

/*
**check if surrounded by walls
**return 1 if if it does
**return - if it's not
** in order West/South/East/North
*/
int	check_walls(char **map, t_map *map_data, unsigned int i, unsigned int j)
{
	while (i < map_data->ymax - 1)
	{
		if (map[i][j] != CHAR_WALL)
			return (0);
		i++;
	}
	while (j < map_data->xmax - 1)
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
int	check_collectible( t_map *map, char **line)
{
	int	i;
	int	j;

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
**check if exit exist
**return 1 and coordinate if do
**return 0 if not
*/
int	check_exit(t_map *map, char **line)
{
	int	i;
	int	j;

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
int	check_player(t_map *map, char **line)
{
	int	i;
	int	j;

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
				return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}
