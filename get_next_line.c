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
	newstash = ft_calloc(sizeof(char), (len - i + 1));
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
		stash = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!stash)
		return (NULL);
	stash = ft_createstash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_createline(stash);
	stash = ft_restash(stash);
	return (line);
}
