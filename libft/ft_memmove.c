/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:57:01 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/26 20:30:58 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (s > d)
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else
	{
		while (len)
		{
			len--;
			*(d + len) = *(s + len);
		}
	}
	return (dst);
}
