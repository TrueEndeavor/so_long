/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:11 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/04 15:06:38 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_left(t_game_data *game_data)
{
	game_data->bee_x--;
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
		game_data->bee_left_ptr, game_data->bee_x * PIXELS, game_data->bee_y * PIXELS);
}

void	win_right(t_game_data *game_data)
{
	game_data->bee_x++;
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
		game_data->bee_right_ptr, game_data->bee_x * PIXELS, game_data->bee_y * PIXELS);
}

void	win_up(t_game_data *game_data)
{
	game_data->bee_y--;
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
		game_data->bee_up_ptr, game_data->bee_x * PIXELS, game_data->bee_y * PIXELS);
}

void	win_down(t_game_data *game_data)
{
	game_data->bee_y++;
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
		game_data->bee_down_ptr, game_data->bee_x * PIXELS, game_data->bee_y * PIXELS);
}

void	win_game(t_game_data *game_data, char move)
{
	game_data->moves++;
	ft_printf("moves: %d\n", game_data->moves);
	mlx_put_image_to_window(game_data->mlx_ptr, game_data->win_ptr,
		game_data->mini_background_ptr, game_data->bee_x * PIXELS, game_data->bee_y * PIXELS);
	if (move == 'l')
		win_left(game_data);
	if (move == 'r')
		win_right(game_data);
	if (move == 'u')
		win_up(game_data);
	if (move == 'd')
		win_down(game_data);
	ft_printf("WINNER! You must be BUZZING\n");
	destroy(game_data);
}
