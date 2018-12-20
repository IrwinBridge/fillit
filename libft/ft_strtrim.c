/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:38:08 by bbashiri          #+#    #+#             */
/*   Updated: 2018/11/27 15:46:35 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		end;

	if (!s)
		return (0);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && end > i)
		end--;
	str = ft_strsub(s, i, end - i + 1);
	if (!str)
		return (NULL);
	return (str);
}
