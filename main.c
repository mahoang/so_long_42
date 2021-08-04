/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:36:16 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/04 16:11:52 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_map	init_mxl(t_data mlx, int screenx, int screeny)
{
	t_data new;

	new.img = mlx_new_image(mlx.addr, screenx, screeny);
	if (!new.img)
	{
		printf("Unable to create image");
		exit(-1);
	}
		exit(-1);
	new.addr = mlx_get_data_addr(new.img, &new.bpp, &new.line_len, &new.endian);
	if (!new.addr)
	{
		printf("Unable to create image");
		exit(-1);
	}

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
	init_mlx();
}
