/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:40 by lannur-s          #+#    #+#             */
/*   Updated: 2023/12/06 18:43:52 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int ac)
{
	if (ac == 1)
	{
		display_error("so_long needs a map");
		return (0);
	}
	if (ac > 2)
	{
		display_error("Too many arguments to so_long");
		return (0);
	}
	return (1);
}
