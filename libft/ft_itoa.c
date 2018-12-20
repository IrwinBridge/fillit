/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:43:02 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/29 17:08:27 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_countint(n);
	str = ft_strnew(len);
	if (!str)
		return (0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str[len--] = '\0';
	sign = n < 0 ? 1 : 0;
	if (n < 0)
		n *= -1;
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
