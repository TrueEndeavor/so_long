/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:36:05 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/28 12:40:59 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	//t_long	solong;

	if (ac == 1)
	{
		display_error("[ERROR] Oh oh! The game map is missing."\
		"You can pass a map like this: ./so_long maps/sample.ber");
		exit (0);
	}
	if (ac > 2)
	{
		display_error("[ERROR] Too many arguments");
		exit (0);
	}
	if (!check_ber_extension(av[1]))
		exit (0);
/* 	initvar(&solong);
	parsing(&solong, av[1]);
	display(&solong); */
	return (0);
}
