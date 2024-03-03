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

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*stash;
	ssize_t		res;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	res = read(fd, buff, BUFFER_SIZE);
	stash = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	stash = ft_strjoin(stash, buff);
	line = 
}
