/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:36:16 by zephyrus          #+#    #+#             */
/*   Updated: 2021/07/29 16:44:16 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_mapstruct(t_map *map)
{
	map->ymax = 0;
	map->xmax = 0;
}

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_extension(char *c)
{
	int	i;

	i = ft_strlen(c);
	if (c[i - 4] == '.' && c[i - 3 == 'b'] && c[i - 2] == 'e' && c[i - 1] == 'r')
		return (0);
	return (1);
}

int is_error(char *str)
{
	printf("Error\n%s\n", str);
	return (0);
}

int	main(int ac, char *av[])
{
	int	fd;
	char	**map;
	int ret;

	if (ac != 2)
		return (is_error("wrong number of arguments"));
	if (ft_extension(av[1]))
		return (is_error("extension not valid"));
	fd= open(av[1], O_RDONLY);
	if (fd < 0)
		return (is_error("map couldn't open"));
	ret = ft_parsing(av[1], &map);
	//printf("\nreturn %i\n",ret);
	close(fd);
	return (1);
}
