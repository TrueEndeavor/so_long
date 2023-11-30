/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtexture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loadtexture(t_game_data *game_data)
{
	game_data->text[0] = mlx_xpm_file_to_image(game_data->mlx_ptr, "./textures/floor.xpm",
			&game_data->widthtext[0], &game_data->heighttext[0]);
	game_data->ptr_text[0] = mlx_get_data_addr(game_data->text[0],
			&(game_data->bpp_text[0]), &(game_data->sline_text[0]), &(game_data->ed_text[0]));
	game_data->text[1] = mlx_xpm_file_to_image(game_data->mlx_ptr, "./textures/wall.xpm",
			&game_data->widthtext[1], &game_data->heighttext[1]);
	game_data->ptr_text[1] = mlx_get_data_addr(game_data->text[1],
			&(game_data->bpp_text[1]), &(game_data->sline_text[1]), &(game_data->ed_text[1]));
	game_data->text[3] = mlx_xpm_file_to_image(game_data->mlx_ptr, "./textures/player.xpm",
			&game_data->widthtext[3], &game_data->heighttext[3]);
	game_data->ptr_text[3] = mlx_get_data_addr(game_data->text[3],
			&(game_data->bpp_text[3]), &(game_data->sline_text[3]), &(game_data->ed_text[3]));
	game_data->text[2] = mlx_xpm_file_to_image(game_data->mlx_ptr, "./textures/collectible.xpm",
			&game_data->widthtext[2], &game_data->heighttext[2]);
	game_data->ptr_text[2] = mlx_get_data_addr(game_data->text[2],
			&(game_data->bpp_text[2]), &(game_data->sline_text[2]), &(game_data->ed_text[2]));
	game_data->text[4] = mlx_xpm_file_to_image(game_data->mlx_ptr, "./textures/exit.xpm",
			&game_data->widthtext[4], &game_data->heighttext[4]);
	game_data->ptr_text[4] = mlx_get_data_addr(game_data->text[4],
			&(game_data->bpp_text[4]), &(game_data->sline_text[4]), &(game_data->ed_text[4]));
	return (0);
}

int	printtexture(t_game_data *game_data,int starter_X, int starter_Y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game_data->heighttext[game_data->actualtext])
	{
		while (x < game_data->widthtext[game_data->actualtext])
		{
			game_data->color = *(unsigned int *)(game_data->ptr_text[game_data->actualtext]
					+ game_data->sline_text[game_data->actualtext] * y + x
					* (game_data->bpp_text[game_data->actualtext] / 8));
			if (game_data->color != 0)
			{
				put_pxl(game_data,starter_X * 64 + x, starter_Y * 64 + y, game_data->color);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	gettextnum(int X, int Y, t_game_data *game_data)
{
	if (game_data->map[Y][X] == '0' || game_data->map[Y][X] == 'a')
		game_data->actualtext = 0;
	if (game_data->map[Y][X] == '1')
		game_data->actualtext = 1;
	if (game_data->map[Y][X] == 'C')
		game_data->actualtext = 2;
	if (game_data->map[Y][X] == 'E')
		game_data->actualtext = 4;
	if (game_data->map[Y][X] == 'P')
		game_data->actualtext = 0;
	return (0);
}
