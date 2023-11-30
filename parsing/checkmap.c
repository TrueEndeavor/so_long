/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodandfill(t_game_data *game_data,int mapy, int mapx)
{
	if (game_data->map[mapy][mapx] == 'a' ||
	game_data->map[mapy][mapx] == 'c' || game_data->map[mapy][mapx] == 'd'
	|| game_data->map[mapy][mapx] == 'e')
	{
		if (checkaround(mapx, mapy, game_data) == 0)
			showerror(game_data,"Map is not surrounded/closed by wall");
		floodandfill2(game_data,mapy, mapx);
		floodandfill(game_data,mapy, mapx + 1);
		floodandfill(game_data,mapy, mapx - 1);
		floodandfill(game_data,mapy + 1, mapx);
		floodandfill(game_data,mapy - 1, mapx);
	}
	return (1);
}

void	floodandfill2(t_game_data *game_data,int mapy, int mapx)
{
	if (game_data->map[mapy][mapx] == 'a')
		game_data->map[mapy][mapx] = '0';
	if (game_data->map[mapy][mapx] == 'c')
		game_data->map[mapy][mapx] = 'P';
	if (game_data->map[mapy][mapx] == 'd')
	{
		game_data->map[mapy][mapx] = 'E';
		game_data->exitparse++;
	}
	if (game_data->map[mapy][mapx] == 'e')
	{
		game_data->map[mapy][mapx] = 'C';
		game_data->collectibleparse++;
	}
}

int	checkaround(int mapx, int mapy, t_game_data *game_data)
{
	if (mapy == 0 || mapy == game_data->y - 1
		|| mapx == 0 || mapx == game_data->x - 1)
		showerror(game_data,"Map is not surrounded/closed by walls");
	if (checkifgood(game_data->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(game_data->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(game_data->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(game_data->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int	checkthewall(t_game_data *game_data)
{
	int	mapx;
	int	mapy;

	mapy = (int)game_data->player_x;
	mapx = (int)game_data->player_y;
	game_data->collectibleparse = 0;
	game_data->exitparse = 0;
	floodandfill(game_data,mapx, mapy + 1);
	floodandfill(game_data,mapx, mapy - 1);
	floodandfill(game_data,mapx + 1, mapy);
	floodandfill(game_data,mapx, mapy - 1);
	if (game_data->collectibleparse != game_data->collectibletotal)
		showerror(game_data,"Some collectible are out of the map");
	if (game_data->exitparse == 0)
		showerror(game_data,"Exit is out of the map");
	return (0);
}
