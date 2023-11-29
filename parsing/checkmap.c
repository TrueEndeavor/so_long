/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/29 15:13:30 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodandfill(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a' ||
	sl->map[mapy][mapx] == 'c' || sl->map[mapy][mapx] == 'd'
	|| sl->map[mapy][mapx] == 'e')
	{
		if (checkaround(mapx, mapy, sl) == 0)
			showerror(sl, "Map is not surrounded/closed by wall");
		floodandfill2(sl, mapy, mapx);
		floodandfill(sl, mapy, mapx + 1);
		floodandfill(sl, mapy, mapx - 1);
		floodandfill(sl, mapy + 1, mapx);
		floodandfill(sl, mapy - 1, mapx);
	}
	return (1);
}

void	floodandfill2(t_long *sl, int mapy, int mapx)
{
	if (sl->map[mapy][mapx] == 'a')
		sl->map[mapy][mapx] = '0';
	if (sl->map[mapy][mapx] == 'c')
		sl->map[mapy][mapx] = 'P';
	if (sl->map[mapy][mapx] == 'd')
	{
		sl->map[mapy][mapx] = 'E';
		sl->exitparse++;
	}
	if (sl->map[mapy][mapx] == 'e')
	{
		sl->map[mapy][mapx] = 'C';
		sl->collectibleparse++;
	}
}

int	checkaround(int mapx, int mapy, t_long *sl)
{
	if (mapy == 0 || mapy == sl->y - 1
		|| mapx == 0 || mapx == sl->x - 1)
		showerror(sl, "Map is not surrounded/closed by walls");
	if (checkifgood(sl->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(sl->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int	checkthewall(t_long *sl)
{
	int	mapx;
	int	mapy;

	mapy = (int)sl->player_x;
	mapx = (int)sl->player_y;
	sl->collectibleparse = 0;
	sl->exitparse = 0;
	floodandfill(sl, mapx, mapy + 1);
	floodandfill(sl, mapx, mapy - 1);
	floodandfill(sl, mapx + 1, mapy);
	floodandfill(sl, mapx, mapy - 1);
	if (sl->collectibleparse != sl->collectibletotal)
		showerror(sl, "Some collectible are out of the map");
	if (sl->exitparse == 0)
		showerror(sl, "Exit is out of the map");
	return (0);
}
