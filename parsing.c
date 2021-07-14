/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:57:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 22:31:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_parcours(char **map, t_coord *p_pos)
{
	t_coord pos;
	int find;

	pos.x = 0;
	pos.y = 0;
	find = 0;
	while (map[pos.y])
	{
		while (map[pos.y][pos.x])
		{
			if (map[pos.x] == "P")
			{
				find = 1;
				player.pose.x = pos.x;
				player.pose.y = pos.y;
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	if (find == 1)
		exit;
	exit;/*free toussa*/
}


check_map(char **map)
{
	t_coord pos;
	int l;

	pos.x = 0;
	pos.y = 0;
	l = 0;

	while (map[pos.x] == '1')
	{
		pos.x++;
		l++;
	}
	pos.x = 0;
	}
}
