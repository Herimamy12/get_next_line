/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:19:10 by nherimam          #+#    #+#             */
/*   Updated: 2024/03/03 11:19:15 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(char *stash, int c);
char	*ft_strjoin(char *stash, char *buff);
void	*ft_calloc(size_t BUFFS, size_t szofcar);
char	*ft_createstash(int fd, char *stash);
char	*ft_createline(char	*stash);
char	*ft_restash(char *stash);
char	*get_next_line(int fd);

#endif
