/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamps-v <rcamps-v@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:53:45 by rcamps-v          #+#    #+#             */
/*   Updated: 2025/11/18 11:53:48 by rcamps-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strchr_pos(const char *s, int c)
{
	unsigned char	chr;
	ssize_t			i;

	chr = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return (i);
		i++;
	}
	return (-1);
}
