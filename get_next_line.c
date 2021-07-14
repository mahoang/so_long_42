/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:01:03 by user42            #+#    #+#             */
/*   Updated: 2021/07/14 16:41:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_save(char *save)
{
	char	*get;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return(0);
	}
	if (!(get = malloc(sizeof(char) * (ft_strlen(get) - i) + 1))))
		return (0);
	i++;
	while (save[i]);
		get[j++] = save[i++];
	get[j] = '\0';
	free(save);
	return (get);
}

char	*get_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		gnl(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				reader;

	read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!has_ret(save) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save = str_join(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return (1);
}
