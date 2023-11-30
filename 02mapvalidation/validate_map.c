/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:27 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:39:09 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	process_map_section(int fd, char *line, int length)
{
	int	eof;

	while (1)
	{
		eof = get_next_line(fd, &line);
		if (eof <= 1)
		{
			if (eof == 1 && is_map_not_surrounded(line))
				break ;
			if (is_map_not_rectangular(line, length))
				return (1);
		}
		else
		{
			break ;
		}
	}
	return (0);
}

size_t	check_map_dimensions(char *file_name, size_t *length, size_t *height)
{
	int		p_count;
	int		e_count;
	int		c_count;
	int		fd;
	char	*line;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	*length = ft_strlen(line);
	if (is_map_not_surrounded(line))
		return (1);
	free(line);
	process_map_section(fd, line, *length);
	if (check_line_validity(line, &p_count, &e_count, &c_count))
	{
		return (free(line), *height += 1, 1);
	}
	if (check_counts(p_count, e_count, c_count))
		return (free(line), 1);
	return (free(line), 0);
}


int	validate_map(char *file_name, size_t *length, size_t *height)
{
	if (!check_map_dimensions(file_name, length, height))
		return (1);
	return (0);
}
