/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:59 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/03 18:15:36 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_extension(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[i - 4] == '.' && c[i - 3 == 'b']
		&& c[i - 2] == 'e' && c[i - 1] == 'r')
		return (0);
	return (1);
}

int	check_chara(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != '0'
			&& map[i][j] != 'E' && map[i][j] != 'P')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

t_map	init_struct(void)
{
	t_map	map_data;

	map_data.ymax = 0;
	map_data.xmax = 0;
	map_data.collectiblex = 0;
	map_data.collectibley = 0;
	map_data.exitx = 0;
	map_data.exity = 0;
	map_data.playerx = 0;
	map_data.playery = 0;
	return (map_data);
}
/*
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
		printf("\n");
		j = 0;
		i++;
	}
	printf("\n");
	//printf("adresse %p", map[i]);
	return (0);
}
*/
