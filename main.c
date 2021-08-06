/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:36:16 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/06 14:27:21 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
**TODO deplacement
**TODO compteur de deplacement dans le shell
**TODO Keymapping
*/

int	main(int ac, char *av[])
{
	int	fd;
	char	**map;
	int ret;
	t_all all;
	//t_data mlx;
	//t_map map_data;

	all.map_data = init_struct();
	if (ac != 2)
		return (is_error("wrong number of arguments"));
	if (ft_extension(av[1]))
		return (is_error("extension not valid"));
	fd= open(av[1], O_RDONLY);
	if (fd < 0)
		return (is_error("map couldn't open"));
	ret = ft_parsing(av[1], &all.map, &all.map_data);
	printf("\nreturn %i\n",ret);
	printf("\n-mapdata xmax--++%zu", all.map_data.xmax);
	printf("\n-mapdata ymax--++%zu", all.map_data.ymax);
	close(fd);
	//init_mlx(&map, &map_data, &mlx);
}
