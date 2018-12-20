/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:14:18 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/20 00:19:47 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_neighbour(t_fil *tmp)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((tmp->x[i] == tmp->x[j]) && (tmp->y[i] == tmp->y[j] - 1))
				res++;
			if ((tmp->y[i] == tmp->y[j]) && (tmp->x[i] == tmp->x[j] - 1))
				res++;
		}
	}
	return (res == 3 || res == 4);
}

int	check_string(char *str, int res)
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

int	write_structure(t_fil *list, char *str)
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

int	check_start(int fd, t_fil *tetr)
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
		/*if (!check_neighbour(&tetr[i]))
			return (0);*/
		i++;
	}
	return (check == 1 ? i : 0);
}
