/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_recursive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/28 12:00:12 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_line_recursive(int depth, int *status, int fd)
{
	char	buffer[1];
	char	*line;
	int		bytes_read;

	bytes_read = read(fd, buffer, 1);
	if (bytes_read == 0)
		buffer[0] = 0;
	if (buffer[0] == '\n' || buffer[0] == 0)
	{
		line = malloc(sizeof(char) * depth + 1);
		if (!line)
			return (0);
		line[depth] = 0;
		*status = 1;
		if (buffer[0] == 0)
			*status = 0;
		return (line);
	}
	else
	{
		line = read_line_recursive(depth + 1, status, fd);
		line[depth] = buffer[0];
	}
	return (line);
}

int	get_next_line(int fd, char **line)
{
	int	status;

	status = 1;
	*line = read_line_recursive(0, &status, fd);
	return (status);
}
