/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_pxl(t_game_data *game_data,int x, int y, unsigned int c)
{
	char		*dest;

	if (y >= game_data->yscreen || x >= game_data->xscreen || x < 0 \
	|| y < 0)
		return (0);
	dest = game_data->pxl + game_data->s_line * y + x * (game_data->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}

int	visible(t_game_data *game_data)
{
	render(game_data);
	pos_player(game_data);
	mlx_put_image_to_window(game_data->mlx_ptr,
		game_data->mlx_win, game_data->img, 0, 0);
	return (0);
}
