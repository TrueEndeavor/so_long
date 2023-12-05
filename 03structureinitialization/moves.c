/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:02:17 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/05 16:16:54 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->cat_x - 1, data->cat_y);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'l');
	if (check_next_move(data, data->cat_x, data->cat_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->lover_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->cat_x * PIXELS,
			data->cat_y * PIXELS);
	data->cat_x--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player_left_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->cat_x, data->cat_y);
}

void	move_right(t_game_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->cat_x + 1, data->cat_y);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'r');
	if (check_next_move(data, data->cat_x, data->cat_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->lover_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->cat_x * PIXELS,
			data->cat_y * PIXELS);
	data->cat_x++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player_right_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->cat_x, data->cat_y);
}

void	move_up(t_game_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->cat_x, data->cat_y - 1);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'u');
	if (check_next_move(data, data->cat_x, data->cat_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->lover_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->cat_x * PIXELS,
			data->cat_y * PIXELS);
	data->cat_y--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player_up_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->cat_x, data->cat_y);
}

void	move_down(t_game_data *data)
{
	char	next_move;

	next_move = check_next_move(data, data->cat_x, data->cat_y + 1);
	if (next_move == '1')
		return ;
	if (next_move == 'E' && data->collected == data->c_count)
		win_game(data, 'd');
	if (check_next_move(data, data->cat_x, data->cat_y) == 'E'
		&& data->collected != data->c_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->lover_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->mini_background_ptr, data->cat_x * PIXELS,
			data->cat_y * PIXELS);
	data->cat_y++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player_down_ptr, data->cat_x * PIXELS, data->cat_y * PIXELS);
	data->moves++;
	ft_printf("moves: %d\n", data->moves);
	if (next_move == 'C')
		check_collected(data, data->cat_x, data->cat_y);
}

int	on_keypress(int keysym, t_game_data *data)
{
	(void)data;
	if (keysym == 65361 || keysym == 113)
		move_left(data);
	if (keysym == 65363 || keysym == 100)
		move_right(data);
	if (keysym == 65362 || keysym == 122)
		move_up(data);
	if (keysym == 65364 || keysym == 115)
		move_down(data);
	if (keysym == 65307)
		destroy(data);
	return (0);
}
