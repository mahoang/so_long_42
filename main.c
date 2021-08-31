/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:36:16 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/31 23:25:12 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
**TODO deplacement
**TODO compteur de deplacement dans le shell
**TODO compteur collectible
**TODO sortie
**TODO up/down key not working as intended
*/
int	main(int ac, char *av[])
{
	int		fd;
	int		ret;
	t_all	all;
	t_map	map_data;

	map_data = init_struct();
	all.map_data = &map_data;
	if (ac != 2)
		return (is_error("wrong number of arguments"));
	if (ft_extension(av[1]))
		return (is_error("extension not valid"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (is_error("map couldn't open"));
	ret = ft_parsing(av[1], &all);
	close(fd);
	init_mlx(&all);
}
