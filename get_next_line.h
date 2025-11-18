/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:44:38 by rcamps-v          #+#    #+#             */
/*   Updated: 2025/11/18 12:33:47 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/********************************/
/*        EXTERN LIBS           */
/********************************/
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
/********************************/
/*           MACROS             */
/********************************/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
/********************************/
/*          VARIABLES           */
/********************************/

/********************************/
/*           STRUCTS            */
/********************************/

/********************************/
/*          FUNCTIONS           */
/********************************/
char	*get_next_line(int fd);
char	*ft_line(int fd, char *buffer);
char	*ft_join_line(char *line, char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);
ssize_t	ft_strchr_pos(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
