/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:01:32 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/21 17:53:47 by cmelara-         ###   ########.fr       */
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
					map[y + tetr->y[index_y++]][x + tetr->x[index_x++]] = '.';
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
		return (1);
	}
	return (0);
}

int			place_tetrimino(t_fil *tetriminos,
							int i,
							char **map,
							t_prefs prefs)
{
	static int	is_done = 0;
	int			x;
	int			y;

	x = -1;
	y = -1;
	while (++y < prefs.map_size - tetriminos[i].height)
	{
		x = -1;
		while (++x < prefs.map_size - tetriminos[i].width)
		{
			if (i < prefs.tetras_size)
			{
				if (check_possibility(&tetriminos[i], map, x, y))
					is_done = place_tetrimino(tetriminos, i + 1, map, prefs);
				if (is_done)
					return (1);
			}
		}
	}
	if (i < prefs.tetras_size && !is_done)
		revert_map(&tetriminos[i - 1], map, prefs.map_size);
	else
		return (1);
	return (0);
}
