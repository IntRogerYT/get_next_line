/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:54:15 by rcamps-v          #+#    #+#             */
/*   Updated: 2025/11/18 11:58:52 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_line(char *line)
{

}

char	*ft_line(int fd, char *buffer)
{
	char	*line;
	long	bytes;
	ssize_t	endpos;
	char	*tmp;

	line = malloc(BUFFER_SIZE * sizeof(char) + 1);
	bytes = read(fd, line, BUFFER_SIZE);
	if (bytes == 0)
	{
		free(line);
		return (NULL);
	}
	endpos = ft_strchr_pos(line, '\n');
	if (endpos == -1)
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*line;
	if (!*buffer)
		*buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!*buffer)
		return (NULL);
	line = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!line)
		return (NULL);
	line = ft_line(fd, *buffer);
	while (ft_strchr_pos(*buffer, '\n') == -1)
		line = ft_line(fd, *buffer);
}
