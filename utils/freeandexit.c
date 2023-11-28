/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:20 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/28 09:59:00 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	freeandexit(t_long *sl)
{
	if (sl->mlx_ptr != NULL)
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	freemap(sl);
	write(1, "\n\033[31m[so_long closed successfully]\n", 39);
	exit(0);
}

int	freemap(t_long *sl)
{
	int	i;

	i = 0;
	if (sl->maptofree == -1)
		return (1);
	while (i < sl->y)
	{
		free(sl->map[i]);
		i++;
	}
	if (sl->map)
		free(sl->map);
	return (1);
}

int	numberblank(char *str)
{
	int	index;

	index = 0;
	while (str[index] == '\t' || str[index] == '\r'
		|| str[index] == '\v' || str[index] == ' ')
		index++;
	return (index);
}
