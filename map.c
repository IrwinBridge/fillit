/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 23:07:38 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/20 00:56:24 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int map_size)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * (map_size + 1))))
		return (NULL);
	i = 0;
	while (i < map_size + 1)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (map_size + 2))))
			return (NULL);
		i++;
	}
	return (map);
}

char	**init_map(int map_size)
{
	char	**map;
	int		i;
	int		j;

	map = create_map(map_size);
	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size + 1)
		{
			if (j < map_size)
				map[i][j] = '.';
			else
				map[i][j] = '\n';
			j++;
		}
		i++;
	}
	return (map);
}

void	delete_map(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size + 1)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}
