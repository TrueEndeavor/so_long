/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:20 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	freeandexit(t_game_data *game_data)
{
	if (game_data->mlx_ptr != NULL)
		mlx_destroy_window(game_data->mlx_ptr, game_data->mlx_win);
	freemap(game_data);
	write(1, "\n\033[31m[so_long closed successfully]\n", 39);
	exit(0);
}

int	freemap(t_game_data *game_data)
{
	int	i;

	i = 0;
	if (game_data->maptofree == -1)
		return (1);
	while (i < game_data->y)
	{
		free(game_data->map[i]);
		i++;
	}
	if (game_data->map)
		free(game_data->map);
	return (1);
}

int	numberblank(char *str)
{
	int	index;

	index = 0;
	while (str[index] == '\t' || str[index] == '\r'
		|| str[index] == '\v' || str[index] == ' ')
		index++;
	return (index);
}
