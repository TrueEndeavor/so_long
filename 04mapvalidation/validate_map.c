/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:44:27 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/04 16:15:25 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game_data *game_data)
{
	if (!check_rectangle(game_data))
		return (0);
	if (!check_size(game_data))
		return (0);
	if (!check_chars(game_data))
		return (0);
	if (!check_walls(game_data))
	{
		ft_printf("Error\nInvalid walls\n");
		return (0);
	}
	game_data->c_count = 0;
	game_data->e_count = 0;
	game_data->p_count = 0;
	e_p_c_count(game_data);
	if (game_data->c_count < 1 || game_data->e_count != 1 || game_data->p_count != 1)
	{
		ft_printf("Error\nInvalid exit, start position or collectible count\n");
		return (0);
	}
	if (!check_valid_path(game_data))
		return (0);
	return (1);
}
