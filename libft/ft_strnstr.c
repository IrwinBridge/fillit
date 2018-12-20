/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:32:40 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/26 20:31:35 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		buff;
	char		*h;

	h = (char *)haystack;
	i = 0;
	if ((char)needle[0] == '\0')
		return (h);
	while (h[i] && i < len)
	{
		j = 0;
		buff = i;
		while (h[i] == (char)needle[j] && h[i] && (char)needle[j] && i < len)
		{
			i++;
			j++;
		}
		if ((char)needle[j] == '\0')
			return (&h[buff]);
		i = buff;
		i++;
	}
	return (NULL);
}
