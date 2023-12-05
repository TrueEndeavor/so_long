/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/05 16:31:25 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_game_data	game_data = {0};

	if (!check_args(ac))
		return (0);
	if (!check_ber_extension(av[1]))
		destroy(&game_data);
	dprintf(1, "starting\n");
 	read_and_initialize_map(&game_data, av[1]);
	if (!validate_map(&game_data))
		destroy(&game_data);
	game_data.mlx_ptr = mlx_init();
	if (!game_data.mlx_ptr)
		destroy(&game_data); 
	if (!set_up(&game_data))
	{
		destroy(&game_data);
	}
	game_data.win_ptr = mlx_new_window(game_data.mlx_ptr, game_data.width * PIXELS,
			game_data.height * PIXELS, "Purr-fect Petals Pursuit");
	mlx_hook(game_data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game_data);
	mlx_hook(game_data.win_ptr, DestroyNotify, StructureNotifyMask,
		&destroy, &game_data);
	mlx_loop(game_data.mlx_ptr);
	return (0);
}
