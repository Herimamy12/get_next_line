/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:20:04 by nherimam          #+#    #+#             */
/*   Updated: 2024/03/03 11:20:07 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *stash, int c)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(stash);
	while (i < len)
	{
		tmp = (char *)&stash[i];
		if (stash[i] == (char)c)
			return (tmp);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&stash[i]);
	return (0);
}

char	*ft_strjoin(char *stash, char *buff)
{
	size_t	i;
	char	*str;
	size_t	ls1;
	size_t	ls2;

	ls1 = ft_strlen(stash);
	ls2 = ft_strlen(buff);
	str = (char *)malloc(sizeof(char) * (ls2 + ls1 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ls1)
	{
		str[i] = stash[i];
		i++;
	}
	i = 0;
	while (i < ls2)
	{
		str[i + ls1] = buff[i];
		i++;
	}
	str[i + ls1] = '\0';
	return (str);
}

char	*ft_createstash(int fd, char *stash)
{
	int		nbytes;
	char	c;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	c = '\n';
	nbytes = 1;
	while (!ft_strchr(stash, c) && nbytes != 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_createline(char	*stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
