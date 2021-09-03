/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:36:16 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/03 18:26:58 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_parsing(char *file, t_all *all)
{
	if (get_file(file, &all->map) == -1)
		return (-1);
	if (check_chara(all->map) == -1)
		return (is_error("invalid character in files", all));
	if (check_rectangle(all->map_data, all->map) == 0)
		return (is_error("invalid map shape", all));
	if (check_walls(all->map, all->map_data, 0, 0) == 0)
		return (is_error("map not enclosed by walls", all));
	if (check_collectible(all->map_data, all->map) == 0)
		return (is_error("map doesn't have any collectibles", all));
	if (check_exit(all->map_data, all->map) == 0)
		return (is_error("map doesn't have any exit", all));
	if (check_player(all->map_data, all->map) == 0)
		return (is_error("map doesn't have any character", all));
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
	all.countM = 0;
	if (ac != 2)
		return (is_error("wrong number of arguments", &all));
	if (ft_extension(av[1]))
		return (is_error("extension not valid", &all));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (is_error("map couldn't open", &all));
	ret = ft_parsing(av[1], &all);
	close(fd);
	init_mlx(&all);
}
