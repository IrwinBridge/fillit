/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:14:06 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/29 17:14:54 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		w;

	if (!s)
		return (0);
	i = 0;
	w = ft_countwords(s, c);
	str = (char **)malloc(sizeof(char*) * (w + 1));
	if (!str)
		return (NULL);
	while (w--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub(s, 0, ft_lenchar(s, c));
		if (!str[i])
			return (ft_strdelite(str, i));
		s = s + ft_lenchar(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
