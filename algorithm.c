/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:01:32 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/20 04:00:52 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_placement_possibility(t_fil *tetr, char **map, int x, int y)
{
	int index_x;
	int index_y;

	index_x = 0;
	index_y = 0;
	while (index_x < 4)
	{
		if (map[y + tetr->y[index_y]][x + tetr->x[index_x]] != '.')
			return (0);
		index_x++;
		index_y++;
	}
	return (1);
}

void		revert_map(t_fil *tetr, char **map, int map_size)
{
	int x;
	int y;
	int index_x;
	int index_y;

	x = 0;
	y = 0;
	index_x = 0;
	index_y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			if (map[y][x] == tetr->id)
			{
				while (index_x < 4)
				{
					map[y + tetr->y[index_y]][x + tetr->x[index_x]] = '.';
					index_x++;
					index_y++;
				}
				return ;
			}
			x++;
		}
		y++;
	}
}

int			check_possibility(t_fil *tetr, char **map, int x, int y)
{
	int index_x;
	int index_y;

	index_x = 0;
	index_y = 0;
	if (check_placement_possibility(tetr, map, x, y))
	{
		while (index_x < 4)
		{
			map[y + tetr->y[index_y]][x + tetr->x[index_x]] = tetr->id;
			index_x++;
			index_y++;
		}
		//printf("\n");
		//print_map(map, 10);
		return (1);
	}
	return (0);
}

int			place_tetrimino(t_fil *tetriminos,
							int i,
							int tetras_size,
							char **map,
							int map_size)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
		{
			if (check_possibility(&tetriminos[i], map, x, y) && i < tetras_size)
				if (place_tetrimino(tetriminos, i + 1, tetras_size, map,
											map_size))
					return (1);
			x++;
		}
		y++;
	}
	if (i < tetras_size)
		revert_map(&tetriminos[i - 1], map, map_size);
	else
		return (1);
	return (0);
}
