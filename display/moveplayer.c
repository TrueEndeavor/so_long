/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moveplayer(int nb, t_game_data *game_data)
{
	if (nb == 1)
		if (game_data->map[game_data->player_y - 1][game_data->player_x] != '1')
			displaymove(game_data,nb);
	if (nb == -1)
		if (game_data->map[game_data->player_y + 1][game_data->player_x] != '1')
			displaymove(game_data,nb);
	if (nb == 2)
		if (game_data->map[game_data->player_y][game_data->player_x - 1] != '1')
			displaymove(game_data,nb);
	if (nb == 3)
		if (game_data->map[game_data->player_y][game_data->player_x + 1] != '1')
			displaymove(game_data,nb);
	return (0);
}

int	displaymove(t_game_data *game_data,int nb)
{
	write(1, "\b\b\b\b\b\b\b\b\b\b\b", 12);
	if (nb == 1)
		game_data->player_y--;
	if (nb == -1)
		game_data->player_y++;
	if (nb == 2)
		game_data->player_x--;
	if (nb == 3)
		game_data->player_x++;
	game_data->move++;
	write(1, "MOVE : ", 8);
	ft_putnbr_fd(game_data->move, 1);
	checkaremove(game_data);
	return (0);
}

int	checkaremove(t_game_data *game_data)
{
	if (game_data->map[game_data->player_y][game_data->player_x] == 'C')
	{
		game_data->collectible++;
		game_data->map[game_data->player_y][game_data->player_x] = '0';
	}
	if (game_data->map[game_data->player_y][game_data->player_x] == 'E')
	{
		if (game_data->collectible == game_data->collectibletotal)
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 11);
			write(1, "Congratulation you finish with ", 31);
			ft_putnbr_fd(game_data->move, 1);
			write(1, " moves.\n", 9);
			freeandexit(game_data);
		}
	}
	return (0);
}

int	pos_player(t_game_data *game_data)
{
	if (game_data->lastplayer_x != -1)
	{
		gettextnum(game_data->lastplayer_x, game_data->lastplayer_y, game_data);
		printtexture(game_data,game_data->lastplayer_x, game_data->lastplayer_y);
	}
	gettextnum(game_data->player_x, game_data->player_y, game_data);
	printtexture(game_data,game_data->player_x, game_data->player_y);
	game_data->actualtext = 3;
	printtexture(game_data,game_data->player_x, game_data->player_y);
	game_data->lastplayer_x = game_data->player_x;
	game_data->lastplayer_y = game_data->player_y;
	resetkeyboard(game_data);
	return (0);
}

void	resetkeyboard(t_game_data *game_data)
{
	game_data->keyboard[ESC] = 0;
	game_data->keyboard[RIGHT] = 0;
	game_data->keyboard[LEFT] = 0;
	game_data->keyboard[BACK] = 0;
	game_data->keyboard[ADVANCE] = 0;
}
