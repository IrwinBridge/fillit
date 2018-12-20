/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:15:35 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/27 15:44:12 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t					i;
	const unsigned char		*s;
	unsigned char			*d;
	unsigned char			ch;

	ch = (unsigned char)c;
	s = src;
	d = dst;
	i = 0;
	while (i < n)
	{
		*(d + i) = *((s + i));
		if (*(s + i) == ch)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
