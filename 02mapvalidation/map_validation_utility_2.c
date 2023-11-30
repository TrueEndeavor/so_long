/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utility_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:33:16 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 12:02:59 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_not_surrounded(char *line)
{
	if (check_surrounded(line))
	{
		free(line);
		return (1);
	}
	return (0);
}

int	is_map_not_rectangular(char *line, size_t prev_length)
{
	size_t	current_line_len;

	current_line_len = strlen(line);
	if (current_line_len != prev_length)
	{
		display_error("Map is not rectangular.");
		free(line);
		return (1);
	}
	return (0);
}

int	check_counts(int p_count, int e_count, int c_count)
{
	if (p_count > 1 || e_count > 1 || p_count < 1 || e_count < 1 \
		|| c_count < 1)
	{
		if (p_count > 1)
			display_error("More players found.");
		if (e_count > 1)
			display_error("More exits found.");
		if (p_count < 1)
			display_error("There must be at least one player.");
		if (e_count < 1)
			display_error("There must be at least one exit.");
		if (c_count < 1)
			display_error("There must be at least one collectible.");
		return (1);
	}
	return (0);
}
