/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:14:18 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/20 06:28:46 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_neighbour(char *str)
{
	int connections;
	int i;

	i = 0;
	connections = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				connections++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				connections++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				connections++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				connections++;
		}
		i++;
	}
	return (connections == 6 || connections == 8);
}

int		check_string(char *str, int res)
{
	int		count;
	int		i;

	if (res != 21 && res != 20)
		return (0);
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (str[i] != '\n')
				return (0);
			i++;
			if (res == 20 && i == 20)
				return (str[i] == '\0');
			i += (i == 20);
		}
		if (str[i] != '.' && str[i] != '#')
			return (str[i] == '\0');
	}
	return (1);
}

int		write_structure(t_fil *list, char *str)
{
	int			i;
	int			index;
	int			x_offset;
	int			y_offset;
	static char	c = 'A';

	i = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			list->x[index] = i % 5;
			list->y[index] = i / 5;
			x_offset = (list->id != c) ? list->x[0] : x_offset;
			y_offset = (list->id != c) ? list->y[0] : y_offset;
			list->x[index] -= x_offset;
			list->y[index] -= y_offset;
			list->id = c;
			index++;
		}
		i++;
	}
	c++;
	return (index == 4);
}

void	fill_width_height(t_fil *list)
{
	list->width = 0;
	list->height = 0;
	list->width = list->x[3] - list->x[0];
	list->height = list->y[3] - list->y[0];
}

int		check_start(int fd, t_fil *tetr)
{
	int		check;
	t_fil	list;
	int		i;
	char	buff[BUFF_SIZE + 1];
	int		res;

	i = 0;
	while ((res = read(fd, buff, BUFF_SIZE)))
	{
		buff[res] = '\0';
		check = check_string(buff, res);
		check = (res == 20 && check == 1);
		if (!write_structure(&list, buff))
			return (0);
		tetr[i] = list;
		if (!check_neighbour(buff))
			return (0);
		fill_width_height(&tetr[i]);
		i++;
	}
	return (check == 1 ? i : 0);
}
