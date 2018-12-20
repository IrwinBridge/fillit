/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:06:33 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/29 13:21:20 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;
	size_t		i;

	i = 0;
	ptr = (const char *)s;
	while (i < n)
	{
		if (*(ptr + i) == (char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
