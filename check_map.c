/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:47:02 by zephyrus          #+#    #+#             */
/*   Updated: 2021/07/29 14:32:19 by zephyrus         ###   ########.fr       */
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
int check_rectangle(t_map *map,char **line)
{
	size_t i;
	int j;

	i = 1;
	j = 0;

	while (line[i][j])
		j++;
	map->col_max = j;
	//printf("col max%zu\n", map->col_max);
	j = 0;
	while (line[i] != NULL)
	{
		//printf("coucou\n");
		printf("i %zu\n", i);
		printf("strlen %zu\n", ft_strlen(line[i]));
		if(map->col_max != ft_strlen(line[i]))
			return (0);
		i++;
		printf("--------------\n");
	}
	printf("******************\n");
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
	printf("eeeeeee\n");
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
	printf("dddddddddd/n");
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
	t_map struc;
	struc.lines = 0;
	struc.col_max = 0;
	struc.collectiblex = 0;
	struc. collectibley = 0;
}
int	ft_parsing(char *file, char ***map)
{
	t_map struc;
	init_struct();
	if (get_file(file, map) == -1)
		return (-1);
	testprint(*map);
	if (check_rectangle(&struc, *map) == 0)
		return (3);
	if (check_walls(*map) == 0)
		return (4);
	if (check_collectible(&struc, *map) == 0)
		return (5);
	if (check_exit(&struc, *map) == 0)
		return (6);
	if (check_player(&struc, *map) == 0)
		return (7);
	printf("col_max %zu", struc.col_max);
	printf("\n1");
	return (1);
}
