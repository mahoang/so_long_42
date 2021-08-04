/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:58:59 by zephyrus          #+#    #+#             */
/*   Updated: 2021/08/04 15:24:09 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
	exit(-1);
}
