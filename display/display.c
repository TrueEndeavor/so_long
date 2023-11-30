/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:03:00 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display(t_game_data *game_data)
{
	createwindow(game_data);
	loadtexture(game_data);
	render(game_data);
	write(1, "[ so_long launch successfully ]\n", 43);
	write(1, "MOVE : ", 8);
	ft_putnbr_fd(game_data->move, 1);
	pos_player(game_data);
	mlx_put_image_to_window(game_data->mlx_ptr,
		game_data->mlx_win, game_data->img, 0, 0);
	go_hooking(game_data);
	return (0);
}

int	go_hooking(t_game_data *game_data)
{
	mlx_hook(game_data->mlx_win, 2, 1L, ft_key_hit, game_data);
	mlx_hook(game_data->mlx_win, 15, 1L << 16, visible, game_data);
	mlx_hook(game_data->mlx_win, CLOSERED, 1L << 17, closebyredbutton, game_data);
	mlx_loop_hook(game_data->mlx_ptr, key_loop, game_data);
	mlx_loop(game_data->mlx_ptr);
	return (0);
}

int	key_loop(t_game_data *game_data)
{
	ft_keyboard(game_data);
	if (game_data->keyboard[ESC] == 1 || game_data->keyboard[RIGHT] == 1
		|| game_data->keyboard[LEFT] == 1 || game_data->keyboard[BACK] == 1
		|| game_data->keyboard[ADVANCE] == 1)
	{
		pos_player(game_data);
		mlx_put_image_to_window(game_data->mlx_ptr,
			game_data->mlx_win, game_data->img, 0, 0);
	}
	return (0);
}

int	render(t_game_data *game_data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game_data->y)
	{
		while (x < game_data->x)
		{
			game_data->casein++;
			gettextnum(x, y, game_data);
			printtexture(game_data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	createwindow(t_game_data *game_data)
{
	game_data->mlx_ptr = mlx_init();
	game_data->img = mlx_new_image(game_data->mlx_ptr, game_data->xscreen, game_data->yscreen);
	game_data->pxl = mlx_get_data_addr(game_data->img,
			&(game_data->bpp), &(game_data->s_line),
			&(game_data->ed));
	game_data->mlx_win = mlx_new_window(game_data->mlx_ptr, game_data->xscreen,
			game_data->yscreen, "42 so_long lannur-s");
	return (0);
}
