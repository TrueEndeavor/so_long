/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/04 11:49:36 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int ac)
{
	if (ac == 1)
	{
		display_error("[ERROR] So long needs a map");
		return (0);
	}
	if (ac > 2)
	{
		display_error("[ERROR] Too many arguments");
		return (0);
	}
	return (1);
}
