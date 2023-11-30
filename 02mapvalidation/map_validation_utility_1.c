/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utility_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:11:01 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 12:03:56 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_surrounded(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = strlen(line);
	while (i < len && line[i] != '\0')
	{
		if (line[i] != '1')
		{
			display_error("Map is not surrounded/closed by walls.");
			free(line);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_sidewalls(char *line)
{
	int		len;

	len = strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
	{
		display_error("The sides of the map must be surrounded by '1'.");
		free(line);
		return (1);
	}
	return (0);
}

int	check_valid_character(char *line)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = strlen(line);
	while (i < len && line[i] != '\0')
	{
		c = line[i];
		if (!(c == '1' || c == '0' \
			|| c == 'E' || c == 'P' || c == 'C' \
			|| c == 'e' || c == 'p' || c == 'c'))
		{
			display_error("Found an invalid character in the map file.");
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_char(char *line, char c)
{
	int		count;
	size_t	i;
	size_t	len;

	i = 0;
	count = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_line_validity(char *line, int *p_count, int *e_count, int *c_count)
{
	if (check_valid_character(line) == 1 || check_sidewalls(line) == 1)
		return (1);
	*p_count += count_char(line, 'P');
	*p_count += count_char(line, 'p');
	*e_count += count_char(line, 'E');
	*e_count += count_char(line, 'e');
	*c_count += count_char(line, 'C');
	*c_count += count_char(line, 'c');
	return (0);
}
