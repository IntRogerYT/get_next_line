/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:54:15 by rcamps-v          #+#    #+#             */
/*   Updated: 2025/11/18 14:51:38 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*startstr;
	char	*substr;
	size_t	i;

	startstr = (char *)(s + start);
	if (len > ft_strlen(startstr))
		substr = malloc(ft_strlen(startstr) + 1);
	else
		substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && startstr[i] != '\0')
	{
		substr[i] = startstr[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(size + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, size + 1);
	return (newstr);
}

char	*ft_line(int fd, char *buffer)
{
	char	*line;
	long	bytes;
	ssize_t	endpos;
	char	*tmp;

	line = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
	bytes = read(fd, line, BUFFER_SIZE);
	if (bytes == 0)
	{
		free(line);
		return (NULL);
	}
	endpos = ft_strchr_pos(line, '\n');
	if (endpos == -1)
		return (line);
	tmp = ft_substr(line, 0, endpos + 1);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	char		*tmp2;
	ssize_t		endpos;

	if (!buffer)
		buffer = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	line = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
	if (!line)
		return (NULL);
	line = ft_line(fd, buffer);
	if (!line)
		return (NULL);
	while (ft_strchr_pos(buffer, '\n') == -1)
	{
		tmp = ft_calloc(1, sizeof(buffer) + 1);
		tmp = buffer;
		buffer = ft_strjoin(tmp, line);
		free(tmp);
		if (ft_strchr_pos(buffer, '\n') >= 0)
		{
			endpos = ft_strchr_pos(line, '\n');
			tmp2 = ft_calloc(1, BUFFER_SIZE * sizeof(char) + 1);
			tmp2 = ft_substr(line, endpos + 1 , BUFFER_SIZE - endpos - 1);
			line = buffer;
			buffer = tmp2;
			free(tmp2);
			break;
		}
		line = ft_line(fd, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}
