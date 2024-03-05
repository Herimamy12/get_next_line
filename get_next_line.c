/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:19:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/03/03 11:19:41 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_restash(char *stash)
{
	int		i;
	int		j;
	char	*newstash;
	size_t	len;

	i = 0;
	len = ft_strlen(stash);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newstash = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!newstash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		newstash[j++] = stash[i++];
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	stash = ft_createstash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_createline(stash);
	stash = ft_restash(stash);
	return (line);
}
