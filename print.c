/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:52:50 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/20 03:25:44 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_pieces(t_fil *tetras, int tetras_size)
{
	int i;
	int j;

	i = 0;
	while (i < tetras_size)
	{
		j = 0;
		while (j < 4)
		{
			printf("(x: %d, ", tetras[i].x[j]);
			printf("y: %d) ", tetras[i].y[j]);
			j++;
		}
		putchar('\n');
		i++;
	}
	printf("\n");
}

void	print_piece(t_fil *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		printf("(x: %d, ", tetrimino->x[i]);
		printf("y: %d) ", tetrimino->y[i]);
		i++;
	}
	putchar('\n');
}
