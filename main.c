/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:11:33 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/21 17:53:54 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	solve(t_prefs prefs, char **map, t_fil *tetras)
{
	prefs.map_size = 2;
	map = init_map(prefs.map_size);
	while (1)
	{
		place_tetrimino(tetras, 0, map, prefs);
		if (is_map_blank(map, prefs.map_size))
		{
			delete_map(map, prefs.map_size);
			prefs.map_size++;
			map = init_map(prefs.map_size);
		}
		else
			break ;
	}
	print_map(map, prefs.map_size);
}

int			main(int ac, char **av)
{
	int		fd;
	t_fil	tetras[26];
	t_prefs	prefs;
	char	**map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if ((prefs.tetras_size = check_start(fd, tetras)) == 0)
	{
		ft_putendl("error");
		return (1);
	}
	map = NULL;
	solve(prefs, map, tetras);
	close(fd);
	return (0);
}
