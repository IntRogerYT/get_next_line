/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:44:38 by rcamps-v          #+#    #+#             */
/*   Updated: 2025/11/18 11:45:56 by rcamps-v         ###   ########.fr       */
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
char	*ft_trim_line(char *line);
ssize_t	ft_strchr_pos(const char *s, int c);
#endif
