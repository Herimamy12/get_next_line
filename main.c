/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:17:15 by nherimam          #+#    #+#             */
/*   Updated: 2024/03/06 13:17:17 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	char	*line;
	char	*line2;

	i = 0;
	fd = open("file", O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf ("%s", line);
		i++;
	}
	close(fd);
	return (0);
}
