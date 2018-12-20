/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:12:24 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/29 17:12:39 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdelite(char **s, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
