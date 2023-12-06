/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:26 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/06 18:49:30 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_flood_fill(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->dup_map[j])
	{
		i = 0;
		while (data->dup_map[j][i])
		{
			if (data->dup_map[j][i] == 'E')
			{
				display_error("Exit not reachable");
				return (0);
			}
			if (data->dup_map[j][i] == 'C')
			{
				display_error("Collectible not reachable");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	flood_fill(int x, int y, t_data *data)
{
	if (data->dup_map[y][x] == '1' || data->dup_map[y][x] == 'V')
		return (0);
	data->dup_map[y][x] = 'V';
	if (flood_fill(x, y - 1, data) || flood_fill(x, y + 1, data)
		|| flood_fill(x - 1, y, data) || flood_fill(x + 1, y, data))
		return (1);
	return (0);
}

int	set_dup_map(t_data *data)
{
	int		i;
	t_list	*current;

	data->dup_map = ft_calloc((data->height + 1), sizeof(char *));
	if (!data->dup_map)
	{
		display_error("Could not duplicate map");
		return (0);
	}
	i = 0;
	current = data->map;
	while (current)
	{
		data->dup_map[i] = ft_strdup(current->content);
		if (!data->dup_map[i])
		{
			display_error("Could not duplicate map");
			return (0);
		}
		i++;
		current = current->next;
	}
	return (1);
}

int	check_valid_path(t_data *data)
{
	int	i;
	int	j;

	if (!set_dup_map(data))
		return (0);
	j = 0;
	while (data->dup_map[j])
	{
		i = 0;
		while (data->dup_map[j][i])
		{
			if (data->dup_map[j][i] == 'P')
			{
				data->start_x = i;
				data->start_y = j;
			}
			i++;
		}
		j++;
	}
	flood_fill(data->start_x, data->start_y, data);
	j = 0;
	if (!check_flood_fill(data))
		return (0);
	return (1);
}
