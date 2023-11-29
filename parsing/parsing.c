/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:58:08 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/29 19:11:40 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(t_long *sl, char *argv)
{
	mallocmap(sl);
	stockmap(sl, argv);
	checkmap(sl);
	return (0);
}
/* 
int	get_x_and_y(t_long *sl, char *filename)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	ret = get_next_line(fd, &line);
	sl->oldx = ft_strlen(line);
	while (line[numberblank(line)] == '1' || line[numberblank(line)] == '0')
	{
		sl->x = ft_strlen(line);
		if (sl->x != sl->oldx)
			showerror(sl, "Map is not rectangular");
		sl->oldx = sl->x;
		if (ret != -1)
			free(line);
		ret = get_next_line(fd, &line);
		sl->y++;
	}
	if (sl->y == 0 || sl->x == 0)
		showerror(sl, "Map is not correct or not well formated");
	sl->yscreen = sl->y * 64;
	free(line);
	sl->xscreen = sl->x * 64;
	close(fd);
	return (0);
} */

char	replacechar(char c)
{
	if (c == '0')
		return ('a');
	if (c == '1')
		return ('1');
	if (c == 'P')
		return ('c');
	if (c == 'E')
		return ('d');
	if (c == 'C')
		return ('e');
	return (0);
}


