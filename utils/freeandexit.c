/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeandexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:20 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/25 14:04:06 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	freeandexit(t_long *sl)
{
	if (sl->mlx_ptr != NULL)
		mlx_destroy_window(sl->mlx_ptr, sl->mlx_win);
	freemap(sl);
	write(1, "\n\033[31m[ so_long closed successfully ]\n", 39);
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

int	showerror(t_long *sl, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	freeandexit(sl);
	return (0);
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
