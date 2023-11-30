/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/30 09:54:25 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int ac)
{
	if (ac == 1)
	{
		display_error("[ERROR] Oh oh! The game map is missing."\
		"You can pass a map like this: ./so_long maps/sample.ber");
		return (1);
	}
	if (ac > 2)
	{
		display_error("[ERROR] Too many arguments");
		return (1);
	}
	return (0);
}
