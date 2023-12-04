/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:10:26 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/04 14:22:24 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_flood_fill(t_game_data *game_data)
{
	int	i;
	int	j;

	j = 0;
	while (game_data->dup_map[j])
	{
		i = 0;
		while (game_data->dup_map[j][i])
		{
			if (game_data->dup_map[j][i] == 'E')
			{
				ft_printf("Error\nExit not reachable\n");
				return (0);
			}
			if (game_data->dup_map[j][i] == 'C')
			{
				ft_printf("Error\nCollectible not reachable\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	flood_fill(int x, int y, t_game_data *game_data)
{
	if (game_data->dup_map[y][x] == '1' || game_data->dup_map[y][x] == 'V')
		return (0);
	game_data->dup_map[y][x] = 'V';
	if (flood_fill(x, y - 1, game_data) || flood_fill(x, y + 1, game_data)
		|| flood_fill(x - 1, y, game_data) || flood_fill(x + 1, y, game_data))
		return (1);
	return (0);
}

int	set_dup_map(t_game_data *game_data)
{
	int		i;
	t_list	*current;

	game_data->dup_map = ft_calloc((game_data->height + 1), sizeof(char *));
	if (!game_data->dup_map)
	{
		ft_printf("Error\nCould not duplicate map\n");
		return (0);
	}
	i = 0;
	current = game_data->map;
	while (current)
	{
		game_data->dup_map[i] = ft_strdup(current->content);
		if (!game_data->dup_map[i])
		{
			ft_printf("Error\nCould not duplicate map\n");
			return (0);
		}
		i++;
		current = current->next;
	}
	return (1);
}

int	check_valid_path(t_game_data *game_data)
{
	int	i;
	int	j;

	if (!set_dup_map(game_data))
		return (0);
	j = 0;
	while (game_data->dup_map[j])
	{
		i = 0;
		while (game_data->dup_map[j][i])
		{
			if (game_data->dup_map[j][i] == 'P')
			{
				game_data->start_x = i;
				game_data->start_y = j;
			}
			i++;
		}
		j++;
	}
	flood_fill(game_data->start_x, game_data->start_y, game_data);
	j = 0;
	if (!check_flood_fill(game_data))
		return (0);
	return (1);
}
