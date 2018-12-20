/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:11:33 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/20 03:54:29 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_fil	tetras[26];
	int		tetras_size;
	char	**map;
	int		map_size;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if ((tetras_size = check_start(fd, tetras)) == 0)
	{
		printf("check: error");
		return (1);
	}
	map_size = 10;
	map = init_map(map_size);
	place_tetrimino(tetras, 0, tetras_size, map, map_size);
	printf("\n");
	print_map(map, map_size);
	close(fd);
	return (0);
}
