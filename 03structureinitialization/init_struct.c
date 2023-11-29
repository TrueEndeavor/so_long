/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:20 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/29 19:11:05 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_struct(t_long *sl)
{
	sl->keyboard[BACK] = 0;
	sl->keyboard[RED_BUTTON] = 0;
	sl->keyboard[ESC] = 0;
	sl->keyboard[LEFT] = 0;
	sl->keyboard[RIGHT] = 0;
	sl->keyboard[ADVANCE] = 0;
	sl->bpp = 0;
	sl->casein = 0;
	sl->casetotal = 0;
	sl->y = 0;
	sl->x = 0;
	sl->collectible = 0;
	sl->collectibletotal = 0;
	sl->s_line = 0;
	sl->maptofree = -1;
	sl->move = 0;
	sl->playerset = 0;
	sl->collectibleset = 0;
	sl->exitset = 0;
	sl->lastplayer_x = -1;
	sl->lastplayer_y = -1;
	sl->mlx_ptr = NULL;
	return (0);
}

int	mallocmap(t_long *sl)
{
	int	i;

	i = 0;
	sl->map = malloc(sizeof(char *) * sl->y);
	while (i < sl->y)
	{
		sl->map[i] = malloc(sizeof(char) * (sl->x + 1));
		i++;
	}
	sl->maptofree = 1;
	return (1);
}