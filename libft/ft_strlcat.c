/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:44:05 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/26 20:43:48 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(dst);
	if (len > size)
		return (ft_strlen(src) + size);
	size--;
	while (src[i] && len < size)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	if (src[i] != '\0')
	{
		while (src[i])
		{
			i++;
			len++;
		}
	}
	return (len);
}
