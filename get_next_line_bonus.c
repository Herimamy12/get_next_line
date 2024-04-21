/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:24:39 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/21 10:30:27 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t BUFFS, size_t szofcar)
{
	char	*stash;
	size_t	i;

	i = 0;
	stash = (char *)malloc(BUFFS * szofcar);
	if (!stash)
		return (NULL);
	while (i < (BUFFS * szofcar))
	{
		stash[i] = '\0';
		i++;
	}
	return ((void *)stash);
}

char	*ft_restash(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || stash[i + 1] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	newstash = ft_calloc(sizeof(char), (ft_strlen(stash) - i + 1));
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
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	stash[fd] = ft_createstash(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = ft_createline(stash[fd]);
	stash[fd] = ft_restash(stash[fd]);
	return (line);
}
