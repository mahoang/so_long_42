/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:01:03 by user42            #+#    #+#             */
/*   Updated: 2021/07/10 12:17:23 by user42           ###   ########.fr       */
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
