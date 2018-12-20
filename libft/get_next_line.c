/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:20:34 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/06 17:09:46 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_line(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	return (i);
}

static char		*ft_remain(char **content)
{
	char	*right;
	char	*tmp;

	if ((right = ft_strchr(*content, '\n')))
		right++;
	else
	{
		ft_strdel(content);
		return (NULL);
	}
	tmp = ft_strsub(right, 0, ft_strlen(right));
	ft_strdel(content);
	return (tmp);
}

static char		*ft_putall(char *buff, char **content)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(buff) + ft_strlen(*content));
	tmp = ft_strcpy(tmp, *content);
	tmp = ft_strcat(tmp, buff);
	ft_strdel(content);
	return (tmp);
}

static t_get	*lists(t_get **list, size_t fd)
{
	t_get	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_get *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(tmp->content = ft_strnew(0)))
		return (NULL);
	tmp->content_size = 0;
	tmp->fd = fd;
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static	t_get	*list;
	t_get			*tmp;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	tmp = lists(&list, fd);
	if (!tmp->content)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(tmp->content = ft_putall(buf, &tmp->content)))
			return (-1);
		if (ft_strchr(tmp->content, '\n'))
			break ;
	}
	*line = ft_strsub(tmp->content, 0, ft_line(tmp->content));
	if (ret < BUFF_SIZE && !ft_strlen(tmp->content))
		return (0);
	tmp->content = ft_remain(&tmp->content);
	return (1);
}
