/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:36:51 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/29 13:01:00 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long		res;
	int				znak;

	znak = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (ft_strlen(str) >= 19 && ft_strcmp(str, "9223372036854775807") >= 0)
		return (-1);
	if (ft_strlen(str) >= 20 && ft_strcmp(str, "-9223372036854775808") >= 0)
		return (0);
	if (str[i] == '-')
	{
		znak = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
	}
	return (res * znak);
}
