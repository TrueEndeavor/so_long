/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:37:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hit(int keycode, t_game_data *game_data)
{
	game_data->keyboard[keycode] = 1;
	return (0);
}

int	ft_keyboard(t_game_data *game_data)
{
	if (game_data->keyboard[ADVANCE])
		moveplayer(1, game_data);
	if (game_data->keyboard[BACK])
		moveplayer(-1, game_data);
	if (game_data->keyboard[LEFT])
		moveplayer(2, game_data);
	if (game_data->keyboard[RIGHT])
		moveplayer(3, game_data);
	if (game_data->keyboard[ESC] == 1 || game_data->keyboard[RED_BUTTON] == 1)
		freeandexit(game_data);
	return (0);
}

int	closebyredbutton(t_game_data *game_data)
{
	freeandexit(game_data);
	game_data->keyboard[79] = 1;
	return (0);
}
