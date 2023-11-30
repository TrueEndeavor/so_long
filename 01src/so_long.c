/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:39:37 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game_data	solong;
	size_t		length;
	size_t		height;

	length = 0;
	height = 1;
	if (check_args(ac))
		exit (0);
	if (check_ber_extension(av[1]))
		exit (0);
	if (validate_map(av[1], &length, &height))
		exit (0);
	init_struct(&solong);
	parsing(&solong, av[1]);
	display(&solong);
	return (0);
}
