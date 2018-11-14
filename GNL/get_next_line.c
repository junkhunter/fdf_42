/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:31:26 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/06 10:53:51 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str, char **rest)
{
	int		i;

	i = 0;
	if (str[0] == '\n')
	{
		if (!(*rest = ft_strdup(str + i + 1)))
		{
			ft_strdel(&str);
			return (NULL);
		}
		return (str);
	}
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\0')
		if (!(*rest = ft_strdup(str + i + 1)))
		{
			ft_strdel(&str);
			return (NULL);
		}
	if (ft_strlen(str) == 1)
		return (str);
	str[i] = '\0';
	return (str);
}

char	*ft_read(char *buf, const int fd)
{
	int				ret;
	char			*tmp;
	char			*str;
	static char		*rest[OPEN_MAX];

	if (rest[fd] == NULL)
		rest[fd] = ft_strnew(0);
	str = ft_strdup(rest[fd]);
	ft_strdel(&rest[fd]);
	while (ft_strchr(str, '\n') == NULL && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp);
		if (str == NULL)
			return (NULL);
	}
	str = ft_line(str, &(rest[fd]));
	return ((ret == -1) ? 0 : str);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!(*line = ft_read(buf, fd)))
		return (-1);
	if (**line == '\n')
	{
		**line = '\0';
		return (1);
	}
	if (**line == 0)
		return (0);
	return (1);
}
