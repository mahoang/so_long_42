/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:36:16 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/01 01:09:13 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_parsing(char *file, t_all *all)
{
	if (get_file(file, &all->map) == -1)
		return (-1);
	if (check_chara(all->map) == -1)
		return (is_error("invalid character in files"));
	if (check_rectangle(all->map_data, all->map) == 0)
		return (is_error("invalid map shape"));
	if (check_walls(all->map, all->map_data, 0, 0) == 0)
		return (is_error("map not enclosed by walls"));
	if (check_collectible(all->map_data, all->map) == 0)
		return (is_error("map doesn't have any collectibles"));
	if (check_exit(all->map_data, all->map) == 0)
		return (is_error("map doesn't have any exit"));
	if (check_player(all->map_data, all->map) == 0)
		return (is_error("map doesn't have any character"));
	return (1);
}

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
