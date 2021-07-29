/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:47:02 by zephyrus          #+#    #+#             */
/*   Updated: 2021/07/29 11:37:06 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong.h"


/*
*TODO faire un main avec scanf ou en dur dans un main pour tester
* voir readline/getline
*dans le test print le tableau et le resultat
*
*/

/*
**check if map is rectangular
**if rectangular return 1
**if not return 0
*/
int check_rectangle(char **line, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (line[i][j])
		j++;
	map->col_max = j;
	j = 0;
	while (line[i++])
	{
		if(map->col_max != ft_strlen(line[i]))
			return (0);
	}
	return (1);
}

/*
**check if surrounded by walls
**return 1 if if it does
**return - if it's not
*/
int check_walls(char **map)
{
	int i = 0;
	int j = 0;

	while (map[i++][j] == '1')
	{
		if (map[i][j] != '1')
			return (0);
	}
	while (map[i][j++])
	{
		if (map[i][j] != '1')
			return (0);
	}
	while (map[i--][j])
	{
		if (map[i][j] != '1')
			return (0);
	}
	while (map[i][j--])
	{
		if (map[i][j] != '1')
			return (0);
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
			j++;
			if (line[i][j] == 'C')
			{
				map->collectiblex = j;
				map->collectibley = i;
				return (1);
			}
		}
		j = 1;
		i++;
	}
	return (0);
}

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
			j++;
			if (line[i][j] == 'E')
			{
				map->exitx = j;
				map->exity = i;
				return (1);
			}
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

	i = 1;
	j = 1;
	while (line[i])
	{
		while (line[i][j])
		{
			j++;
			if (line[i][j] == 'P')
			{
				map->playerx = j;
				map->playery = i;
				return (1);
			}
		}
		j = 1;
		i++;
	}
	return (0);
}

int	ft_parsing(char *file, char ***map)
{
	if (get_file(file, map) == -1)
		return (-1);
	if (check_rectangle(file, map) == 0)
		return (0);
	if (check_walls(map) == 0)
		return (0);
	if (check_collectible(file, map) == 0)
		return (0);
	if (check_exit(file, map) == 0)
		return (0);
	if (check_player(file, map) == 0)
		return (0);
	return (1);
}
