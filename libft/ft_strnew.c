/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:59:18 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/29 11:57:10 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	if (size == (size_t)(-1))
		return (NULL);
	size++;
	ptr = (char *)malloc(sizeof(char) * (size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
