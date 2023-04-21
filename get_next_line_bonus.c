/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:45:15 by mlangloi          #+#    #+#             */
/*   Updated: 2023/04/21 15:45:28 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	line[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = ft_strjoin(0, line[fd]);
	if (ft_clean(line[fd]) > 0)
		return (next_line);
	i = read(fd, line[fd], BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		return (NULL);
	}
	while (i > 0)
	{
		next_line = ft_strjoin(next_line, line[fd]);
		if (ft_clean(line[fd]) > 0)
			return (next_line);
		i = read(fd, line[fd], BUFFER_SIZE);
	}
	return (next_line);
}
