/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:08:09 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/26 20:25:21 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;
	size_t		buff;
	char		*h;
	char		*n;

	n = (char *)needle;
	h = (char *)haystack;
	i = -1;
	if (n[0] == '\0')
		return (h);
	while (h[++i])
	{
		j = 0;
		buff = i;
		while (h[i] == n[j] && h[i] && n[j])
		{
			i++;
			j++;
		}
		if (n[j] == '\0')
			return (&h[buff]);
		i = buff;
	}
	return (NULL);
}
