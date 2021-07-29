/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:13:15 by zephyrus          #+#    #+#             */
/*   Updated: 2021/07/29 11:22:02 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_gnl_recurs(int fd, char **line, int index)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == -1)
		return (ft_error("Le fichier n'existe pas"));
	if (ret == 1 && buf != '\n')
	{
		if (ft_gnl_recurs(fd, line, index + 1) == -1)
			return (-1);
		(*line)[index] = buf;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (!(*line))
			return (ft_error("Malloc line error"));
		(*line)[index] = '\0';
	}
	return (ret);
}

static int	ft_gnl(int fd, char **line)
{
	int	ret;

	ret = ft_gnl_recurs(fd, line, 0);
	if (!line || ret == -1)
		return (-1);
	return (ret);
}

static int	ft_get_file_recurs(int fd, char ***map, int index)
{
	char	*line;
	int		ret;

	ret = ft_gnl(fd, &line);
	if (ret == -1)
		return (-1);
	if (ret >= 1)
	{
		if ((ft_get_file_recurs(fd, map, index + 1)) == -1)
			return (-1);
		(*map)[index] = line;
	}
	else
	{
		(*map) = (char **)malloc(sizeof(char *) * (index + 1));
		(*map)[index] = NULL;
		free(line);
	}
	return (1);
}

int	get_file(char *file, char ***map)
{
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (is_error("Le fichier n'existe pas"));
	ret = ft_get_file_recurs(fd, map, 0);
	close(fd);
	return (ret);
}
