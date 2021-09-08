/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:15:23 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/08 11:15:45 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

int	is_error(char *str, t_all *all)
{
	printf("Error\n%s\n", str);
	free_tab(all->map);
	exit(-1);
}

int	is_error_gnl(char *str)
{
	printf("Error\n%s\n", str);
	exit(-1);
}
